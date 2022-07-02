#pragma once

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
    auto onSearchStatusChanged(Types::SearchStatus status) -> void
    {
        reinterpret_cast<Derived*>(this)->_onSearchStatusChanged(status);
    };

    auto onSearchResultsChanged(std::vector<Types::SearchResult> results) -> void
    {
        reinterpret_cast<Derived*>(this)->_onSearchResultsChanged(std::move(results));
    };
};
} // namespace OnlineSearch::Interface