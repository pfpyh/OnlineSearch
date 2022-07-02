#pragma once

#include "base/Proxy.hpp"
#include "OnlineSearchClientProxy.hpp"

namespace OnlineSearch::Types
{
class ConnectionInfo;
} // namespace OnlineSearch::Types

namespace OnlineSearch::Interface
{
template<typename ProxyType>
class OnlineSearchClient
{
protected :
    OnlineSearchClientProxy<ProxyType>* _proxy = nullptr;

public :
    OnlineSearchClient(OnlineSearchClientProxy<ProxyType>* proxy)
        : _proxy(proxy) {};

public :
    auto connect(const Types::ConnectionInfo& info) -> bool
    {
        return true;
    };
    auto disconnect() -> bool
    {
        return true;
    };
    auto search(const std::string& input) -> bool
    {
        _proxy->onSearchStatusChanged(Types::SearchStatus::Searching);
        std::vector<Types::SearchResult> results;
        {
            Types::SearchResult result;
            result._result = "Test";
            results.push_back(std::move(result));
        }
        _proxy->onSearchResultsChanged(std::move(results));
        _proxy->onSearchStatusChanged(Types::SearchStatus::Done);
        return true;
    };
};
} // namespace OnlineSearch::Interface