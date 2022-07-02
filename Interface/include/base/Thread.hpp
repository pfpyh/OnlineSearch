#pragma once

#include <thread>
#include <memory>
#include <future>
#include <mutex>

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

template<typename ReturnType, uint32_t MAX_WORK_CNT>
class ThreadPool
{
protected :
    class Thread : public ThreadBase<Thread, ReturnType>
    {
    protected :
        std::function<ReturnType()> _thread_work = nullptr;

    public :
        Thread(decltype(_thread_work)& thread_work)
            : _thread_work(thread_work) {};
    };

protected :
    uint32_t _work_cnt = 0;
    std::mutex _lock;

public :
    auto add_work( std::function<ReturnType()>& thread_work ) -> decltype(auto)
    {
        _lock.lock();
        if (_work_cnt < MAX_WORK_CNT)
        {
            Thread t(thread_work);
            auto future = t.run();
            _work_cnt++;
            _lock.unlock();
            return future;
        }
        else
        {

        }
        
        return future;
    };
};
} // namespace OnlineSearch::Base