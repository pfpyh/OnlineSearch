#pragma once

namespace OnlineSearch::Base
{
template <typename T, T INIT_VALUE>
class Type
{
public :
    T _value = INIT_VALUE;

    Type& operator= (const Type& value) 
    { 
        _value = value._value; 
        return (*this);
    }

    Type& operator= (const T& value) 
    { 
        _value = value; 
        return (*this);
    }
};
} // namespace OnlineSearch::Base