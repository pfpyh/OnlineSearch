#include "types/ConnectionInfo.hpp"
#include "interface/OnlineSearchClientProxy.hpp"
#include "interface/OnlineSearchClient.hpp"

#include <iostream>
#include <Windows.h>

using namespace OnlineSearch;

class OnlineSearchClientImpl : public Interface::OnlineSearchClientProxy<OnlineSearchClientImpl>
{
public :
    auto _onSearchResultsChanged(Types::SearchId search_id, std::vector<Types::SearchResult> && results) -> void
    {
        std::cout << "[onSearchResultsChanged] search_id=" << std::to_string(search_id._value) << " size=" << results.size() << std::endl;
        for (auto result : results)
            std::cout << result._result << std::endl;
    };

    auto _onSearchStatusChanged(Types::SearchId search_id, Types::SearchStatus status) -> void
    {
        std::string status_str;
        if (status == Types::SearchStatus::Searching) status_str = "Searching";
        else if (status == Types::SearchStatus::Done) status_str = "Done";
        else if (status == Types::SearchStatus::Done_Error) status_str = "Done_Error";
        else if (status == Types::SearchStatus::Done_NoResults) status_str = "Done_NoResults";

        std::cout << "[onSearchResultsChanged] search_id=" << std::to_string(search_id._value) << " status=" << status_str << std::endl;
    };
};

void main()
{
    Types::ConnectionInfo info;
    info.server_address("address");
    info.server_port((uint8_t)3360);
    info.client_id("client");

    OnlineSearchClientImpl impl;
    Interface::OnlineSearchClient<decltype(impl)> client(&impl);

    if (client.connect(info))
    {
        for (uint8_t cnt = 0; cnt < 100; ++cnt)
        {
            auto search_id = client.search("Temp");
            std::cout << "Search [searchid=" << std::to_string(search_id._value) << "]" << std::endl;
        }
    }

    Sleep(1000);

    client.disconnect();
}