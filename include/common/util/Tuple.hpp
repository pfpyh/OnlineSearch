#pragma once

#include <tuple>
#include <utility>
#include <type_traits>
#include <stdexcept>
#include <cassert>

namespace OnlineSearch::Utils
{
template<typename Tuple, typename Indices = std::make_index_sequence<std::tuple_size<Tuple>::value>>
struct runtime_get_func_table;

template<typename Tuple, size_t ... Indices>
struct runtime_get_func_table<Tuple, std::index_sequence<Indices...>>
{
    using return_type = typename std::tuple_element<0, Tuple>::type&;
    using get_func_ptr = return_type(*)(Tuple&) noexcept;

    static constexpr get_func_ptr table[std::tuple_size<Tuple>::value] =
    {
        &std::get<Indices>...
    };
};

template<typename Tuple, size_t ... Indices>
constexpr typename
runtime_get_func_table<Tuple, std::index_sequence<Indices...>>::get_func_ptr
runtime_get_func_table<Tuple, std::index_sequence<Indices...>>::table[std::tuple_size<Tuple>::value];

template<typename Tuple>
constexpr auto runtime_get(Tuple&& t, size_t index) -> typename std::tuple_element<0, typename std::remove_reference<Tuple>::type>::type&
{
    using tuple_type = typename std::remove_reference<Tuple>::type;
    if (index >= std::tuple_size<tuple_type>::value)
        throw std::runtime_error("Out of range");
    return runtime_get_func_table<tuple_type>::table[index](t);
}
namespace Temp
{
template<size_t TupleSize>
struct runtime_get_helper
{
    template<typename Tuple>
    static auto get(Tuple& tuple, size_t idx) -> decltype(auto)
    {
        if (idx == TupleSize - 1)
            return std::get<TupleSize - 1>(tuple);
        else runtime_get_helper<TupleSize - 1>::get(tuple, idx);
    }
};

template<>
struct runtime_get_helper<0>
{
    template<typename Tuple>
    static auto get(Tuple& tuple, size_t idx) -> decltype(auto)
    {
        assert(false);
    };
};

template<typename... T>
auto runtime_get(const std::tuple<T...>& tuple, size_t idx) -> decltype(auto)
{
    return runtime_get_helper<sizeof...(T)>::get(tuple, idx);
}

template<typename... T>
auto runtime_get(std::tuple<T...>& tuple, size_t idx) -> decltype(auto)
{
    return runtime_get_helper<sizeof...(T)>::get(tuple, idx);
}
} // namespace Temp
} // namespace OnlineSearch::Utils