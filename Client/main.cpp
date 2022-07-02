#include "types/ConnectionInfo.hpp"
#include "interface/OnlineSearchClientProxy.hpp"
#include "interface/OnlineSearchClient.hpp"

#include <iostream>

using namespace OnlineSearch;

class OnlineSearchClientImpl : public Interface::OnlineSearchClientProxy<OnlineSearchClientImpl>
{
public :
    auto _onSearchResultsChanged(std::vector<Types::SearchResult> && results) -> void
    {
        std::cout << "[onSearchResultsChanged] size=" << results.size() << std::endl;
        for (auto result : results)
            std::cout << result._result << std::endl;
    };

    auto _onSearchStatusChanged(Types::SearchStatus status) -> void
    {
        std::cout << "[onSearchResultsChanged] status=" << static_cast<uint8_t>(status) << std::endl;
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
        client.search("Temp");
    }
    client.disconnect();
}