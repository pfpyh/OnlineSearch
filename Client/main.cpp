#include "types/ConnectionInfo.hpp"
#include "interface/OnlineSearchClientProxy.hpp"
#include "interface/OnlineSearchClient.hpp"

#include <iostream>
#include <Windows.h>

using namespace OnlineSearch;

class OnlineSearchClientImpl : public Interface::OnlineSearchClientProxy<OnlineSearchClientImpl>
{
public :
    std::mutex _lcok;

    std::vector<decltype(Types::SearchId::_value)> _done;
    std::vector<decltype(Types::SearchId::_value)> _searching;

public :
    auto _onSearchResultsChanged(Types::SearchId search_id, std::vector<Types::SearchResult> && results) -> void
    {
        if (search_id._value > 100)
        {
            std::cout << "[_onSearchResultsChanged][" << std::to_string(search_id._value) << "]" << std::endl;
        }
        //std::cout << "[onSearchResultsChanged][" << std::to_string(search_id._value) << "] " << std::endl;
    };

    auto _onSearchStatusChanged(Types::SearchId search_id, Types::SearchStatus status) -> void
    {
        std::string status_str;
        if (status == Types::SearchStatus::Searching) status_str = "Searching";
        else if (status == Types::SearchStatus::Done) status_str = "Done";
        else if (status == Types::SearchStatus::Done_Error) status_str = "Done_Error";
        else if (status == Types::SearchStatus::Done_NoResults) status_str = "Done_NoResults";

        if (search_id._value > 100)
        {
            std::cout << "[_onSearchStatusChanged][" << std::to_string(search_id._value) << "] " << status_str << std::endl;
        }

        std::lock_guard<std::mutex> scoped_lock(_lcok);
        if (status == Types::SearchStatus::Searching)
            _searching.push_back(search_id._value);
        else if (status == Types::SearchStatus::Done)
            _done.push_back(search_id._value);
    };
};

void main()
{
    constexpr uint8_t loop_cnt = 100;

    Types::ConnectionInfo info;
    info.server_address("address");
    info.server_port((uint8_t)3360);
    info.client_id("client");

    OnlineSearchClientImpl impl;
    Interface::OnlineSearchClient<decltype(impl)> client(&impl);

    if (client.connect(info))
    {
        for (uint8_t cnt = 0; cnt < loop_cnt; ++cnt)
        {
            auto search_id = client.search("Temp");
        }
    }
    Sleep(1000);
    client.disconnect();

    decltype(Types::SearchId::_value) done_list[loop_cnt] = { 0, };
    for (auto id : impl._done)
        done_list[id - 1] = 1;

    decltype(Types::SearchId::_value) searching_list[loop_cnt] = { 0, };
    for (auto id : impl._searching)
        searching_list[id - 1] = 1;

    std::string done_str;
    for (uint16_t id = 0; id < loop_cnt; ++id)
        if (done_list[id] == 0)
            done_str += std::to_string(id + 1) + ", ";

    std::string searching_str;
    for (uint16_t id = 0; id < loop_cnt; ++id)
        if (searching_list[id] == 1)
            searching_str += std::to_string(id + 1) + ", ";

    std::cout << "Searching job = " << searching_str << std::endl;
    std::cout << "Unfinished job = " << done_str << std::endl;
}