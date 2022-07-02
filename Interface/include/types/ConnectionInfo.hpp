#pragma once

#include "base/Struct.hpp"

#include <stdint.h>
#include <string>

namespace OnlineSearch::Types
{
using SERVER_ADDRESS = std::string;
using SERVER_PORT = uint8_t;
using CLIENT_ID = std::string;

class ConnectionInfo : protected Base::Struct< SERVER_ADDRESS, SERVER_PORT, CLIENT_ID >
{
public :
    ConnectionInfo()
    {
        _values = std::make_tuple("", 0, "");
    }

public :
    auto server_address() -> const SERVER_ADDRESS & {
        return std::get<0>(_values);
    };

    auto server_address(const SERVER_ADDRESS & value) -> void {
        std::get<0>(_values) = value;
    };

    auto server_port() -> SERVER_PORT {
        return std::get<1>(_values);
    };

    auto server_port(SERVER_PORT value) {
        std::get<1>(_values) = value;
    };

    auto client_id() -> const CLIENT_ID& {
        return std::get<2>(_values);
    };

    auto client_id(const CLIENT_ID& value) -> void {
        std::get<2>(_values) = value;
    };
};
} // namespace OnlineSearch::Types