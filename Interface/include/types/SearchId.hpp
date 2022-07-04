#pragma once

#include "base/Type.hpp"
#include "types/ConnectionInfo.hpp"

#include <stdint.h>

namespace OnlineSearch::Types
{
class SearchId : public Base::Type<uint16_t, 0>
{
public :
    constexpr static uint16_t INVALID_ID = 0U;
    constexpr static uint16_t MAX_ID = 1024U;
};
} // namespace OnlineSearch::Types