#pragma once

#include "base/Thread.hpp"

#include <string>
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
    Base::ThreadPool<bool, MAX_THREAD_COUNT > _t_pool;

public :
    auto connect(const Types::ConnectionInfo& info) -> bool;
    auto disconnect() -> bool;
    auto search_async(std::string input, 
                      std::function<void()> prework,
                      std::function<void(std::vector<Types::SearchResult>&&)> postwork) -> bool;
};
} // namespace OnlineSearch::Request