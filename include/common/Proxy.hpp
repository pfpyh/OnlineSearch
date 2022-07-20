#pragma once

#include <unordered_map>
#include <functional>

namespace OnlineSearch::Base
{
template<typename Derived>
class Proxy
{
public :
    auto get() -> Derived*
    {
        return static_cast<Derived*>(this);
    }
};
} // namespace OnlineSearch::Base