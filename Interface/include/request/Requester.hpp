#pragma once

#include "base/Thread.hpp"

#include <string>
#include <future>
#include <functional>

namespace OnlineSearch::Types
{
class ConnectionInfo;
class SearchResult;
} // namespace namespace OnlineSearch::Types

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
    auto connect(const Types::ConnectionInfo& info) -> bool;
    auto disconnect() -> void;
    auto search_async(std::string input, 
                      std::function<void()> prework,
                      std::function<void(std::vector<Types::SearchResult>&&)> postwork) -> bool;
};
} // namespace OnlineSearch::Request