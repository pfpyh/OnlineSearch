#pragma once

#include "common/Thread.hpp"

#include <string>
#include <future>
#include <functional>

namespace OnlineSearch::Interface
{
class SearchResult;
class ConnectionInfo;
} // namespace OnlineSearch::Interface

namespace OnlineSearch::Request
{
class Requester
{
protected :
    static constexpr uint8_t MAX_THREAD_COUNT = 8;
    Base::ThreadPool<void, MAX_THREAD_COUNT > _t_pool;

    bool _activated = false;
    std::mutex _lock;
    std::vector<std::future<void>> _futures;

public :
    auto connect(const Interface::ConnectionInfo& info) -> bool;
    auto disconnect() -> void;
    auto search_async(std::string input, 
                      std::function<void()> prework,
                      std::function<void(std::vector<Interface::SearchResult>&&)> postwork) -> bool;
};
} // namespace OnlineSearch::Request