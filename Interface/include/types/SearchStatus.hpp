#pragma once

#include <stdint.h>

namespace OnlineSearch::Types
{
enum class SearchStatus : uint8_t
{
    Searching,
    Done,
    Done_NoResults,
    Done_Error,
};
} // namespace OnlineSearch::Types