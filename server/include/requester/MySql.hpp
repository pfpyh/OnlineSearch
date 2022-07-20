#pragma once

#include "common/util/Tuple.hpp"
#include "mysql.h"

#include <string>

namespace OnlineSearch::Request::MySql
{
template <typename Derived>
class Base
{
protected :
    MYSQL* _mysql = nullptr;

public :
    auto connect() -> bool
    {
        _mysql = mysql_init(_mysql);
        mysql_real_connect(_mysql,
                           "192.168.0.6",
                           "dev",
                           "pwd0000",
                           "OnlineSearch",
                           3306,
                           NULL,
                           0);
        mysql_query(_mysql, "set names euckr");
        return _mysql;
    };

    auto disconnect() -> void
    {
        static_cast<Proxy*>(this)->_disconnect();

        mysql_close(_mysql);
        _mysql = nullptr;
    };

private :
    class Proxy : public Derived
    {
    public :
        friend void Base::disconnect();
    };
};

template <typename Derived, typename... T>
class Fetch : public Base<Fetch<Derived, T...>>
{
protected :
    MYSQL_RES* _res = nullptr;

protected :
    auto _disconnect() -> void
    {
        if(_res) mysql_free_result(_res);
    };

public :
    auto exec() -> uint32_t
    {
        const std::string query(std::move(static_cast<Proxy*>(this)->_get_query()));
        if (0 == mysql_query(_mysql, query.c_str()))
        {
            _res = mysql_store_result(_mysql);
            return _res->row_count;
        }
        return 0;
    };

    auto fetch(std::tuple<T...> && tuple) -> bool
    {
        constexpr std::size_t tuple_size = std::tuple_size<std::tuple<T...>>::value;

        MYSQL_ROW row;
        if (row = mysql_fetch_row(_res))
        {
            /*for (std::size_t idx = 0; idx < tuple_size; ++idx)
                Utils::runtime_get(std::move(tuple), idx) = row[idx];*/

            for (std::size_t idx = 0; idx < tuple_size; ++idx)
                Utils::Temp::runtime_get(tuple, idx) = row[idx];

            return true;
        }
        else return false;
    };

protected :
    class Proxy : public Derived
    {
    public :
        friend uint32_t Fetch::exec();
    };
};

template <typename Derived, typename... T>
class Exec : public Base<Exec<Derived, T...>>
{
public :
    auto exec() -> void
    {

    };

protected :
    class Proxy : public Derived
    {
    public :
        friend void Exec::exec();
    };
};
} // namespace OnlineSearch::Request::MySql