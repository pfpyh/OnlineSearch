#pragma once

namespace OnlineSearch::Base
{
template <typename T, T INIT_VALUE>
class Type
{
public :
    T _value = INIT_VALUE;
};
} // namespace OnlineSearch::Base