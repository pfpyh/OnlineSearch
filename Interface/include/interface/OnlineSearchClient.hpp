#pragma once

#include "OnlineSearchClientProxy.hpp"

#include "types/ConnectionInfo.hpp"

#include "request/Requester.hpp"

namespace OnlineSearch::Interface
{
template<typename ProxyType>
class OnlineSearchClient
{
protected :
    OnlineSearchClientProxy<ProxyType>* _proxy = nullptr;
    Request::Requester _requester;

public :
    OnlineSearchClient(OnlineSearchClientProxy<ProxyType>* proxy)
        : _proxy(proxy) {};

public :
    auto connect(const Types::ConnectionInfo& info) -> bool
    {
        return _requester.connect(info);
    };
    auto disconnect() -> bool
    {
        return _requester.disconnect();
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