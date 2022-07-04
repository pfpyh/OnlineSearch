#pragma once

#include <thread>
#include <memory>
#include <future>
#include <mutex>
#include <queue>

namespace OnlineSearch::Base
{
template<typename Derived, typename ReturnType>
class ThreadBase
{
protected:
    std::shared_ptr<std::promise<ReturnType>> _promise = nullptr;

public:
    auto run() -> decltype(auto)
    {
        _promise = std::make_shared<std::promise<ReturnType>>();
        std::thread t([this]() {
            _promise->set_value(static_cast<Derived*>(this)->_thread_work());
        });
        t.detach();
        return _promise->get_future();
    };

private :
    class Proxy : public Derived
    {
        friend decltype(auto) ThreadBase::run();
    };
};

template<typename ReturnType, uint8_t MAX_THREAD_COUNT>
class ThreadPool
{
protected:
    std::queue<std::shared_ptr<std::promise<void>>> _promises;
    std::mutex _lock;
    uint8_t _work_cnt;

public:
    auto add_work(std::function<ReturnType()> work) -> std::shared_ptr<std::promise<ReturnType>>
    {
        auto promise = std::make_shared<std::promise<ReturnType>>();
        std::thread t([this, promise, work]()
        {
            auto work_promise = std::make_shared<std::promise<void>>();
            auto work_future = std::make_shared<std::future<void>>(work_promise->get_future());
            _lock.lock();
            if (_work_cnt == MAX_THREAD_COUNT)
            {
                _promises.emplace(std::move(work_promise));
                _lock.unlock();
                work_future->get();
                _lock.lock();
                ++_work_cnt;
            }
            else ++_work_cnt;
            _lock.unlock();

            promise->set_value(work());

            std::lock_guard<std::mutex> lock_guard(_lock);
            if (!_promises.empty())
            {
                _promises.front()->set_value();
                _promises.pop();
            }
            --_work_cnt;
        });
        t.detach();
        return promise;
    }
};
} // namespace OnlineSearch::Base