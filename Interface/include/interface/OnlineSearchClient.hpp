#pragma once

#include "OnlineSearchClientProxy.hpp"

#include "types/ConnectionInfo.hpp"
#include "types/SearchId.hpp"

#include "request/Requester.hpp"

namespace OnlineSearch::Interface
{
template<typename ProxyType>
class OnlineSearchClient
{
protected :
    OnlineSearchClientProxy<ProxyType>* _proxy = nullptr;
    Request::Requester _requester;
    Types::SearchId _search_id;

public :
    OnlineSearchClient(OnlineSearchClientProxy<ProxyType>* proxy)
        : _proxy(proxy) {};

public :
    auto connect(const Types::ConnectionInfo& info) -> bool
    {
        return _requester.connect(info);
    };
    auto disconnect() -> void
    {
        _requester.disconnect();
    };
    auto search(const std::string& input) -> Types::SearchId
    {
        if (_search_id._value > Types::SearchId::MAX_ID)
            _search_id._value = Types::SearchId::INVALID_ID;
        ++_search_id._value;

        const auto search_id = _search_id;

        auto rtn = _requester.search_async(input, 
                                           [this, search_id]() {
            _proxy->onSearchStatusChanged(search_id, Types::SearchStatus::Searching);
        },[this, search_id](std::vector<Types::SearchResult>&& results) {
            if (!results.empty())
            {
                _proxy->onSearchResultsChanged(search_id, results);
                _proxy->onSearchStatusChanged(search_id, Types::SearchStatus::Done);
            }
            else _proxy->onSearchStatusChanged(search_id, Types::SearchStatus::Done_NoResults);
        });

        if (!rtn) _proxy->onSearchStatusChanged(search_id, Types::SearchStatus::Done_Error);

        return search_id;
    };
};
} // namespace OnlineSearch::Interface