#pragma once

#include "types/SearchId.hpp"
#include "types/SearchStatus.hpp"
#include "types/SearchResult.hpp"

#include <stdint.h>
#include <vector>
#include <utility>

namespace OnlineSearch::Interface
{
template <typename Derived>
class OnlineSearchClientProxy
{
public :
    auto onSearchStatusChanged(Types::SearchId search_id, Types::SearchStatus status) -> void
    {
        reinterpret_cast<Derived*>(this)->_onSearchStatusChanged(search_id, status);
    };

    auto onSearchResultsChanged(Types::SearchId search_id, std::vector<Types::SearchResult> results) -> void
    {
        reinterpret_cast<Derived*>(this)->_onSearchResultsChanged(search_id, std::move(results));
    };
};
} // namespace OnlineSearch::Interface