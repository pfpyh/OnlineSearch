#pragma once

#include <tuple>

namespace OnlineSearch::Base
{
template<typename... Types>
class Struct
{
public :
    std::tuple<Types...> _values;
};
} // namespace OnlineSearch::Base