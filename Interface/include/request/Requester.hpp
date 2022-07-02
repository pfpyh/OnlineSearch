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
private :
    class RequestWorker : public Base::ThreadBase<RequestWorker, bool>
    {
    protected :
        auto _thread_work() -> bool
        {

        };
    };

public :
    auto connect(const Types::ConnectionInfo& info) -> bool;
    auto disconnect() -> bool;
    auto search_async(std::string input, std::function<void(std::vector<Types::SearchResult>&)> postwork) -> bool;


};
} // namespace OnlineSearch::Request