#include "request/Requester.hpp"

#include "types/ConnectionInfo.hpp"
#include "types/SearchResult.hpp"

namespace OnlineSearch::Request
{
auto Requester::connect(const Types::ConnectionInfo& info) -> bool
{
    return true;
};

auto Requester::disconnect() -> bool
{
    return true;
};

auto Requester::search_async(std::string input, std::function<void(std::vector<Types::SearchResult>&)> postwork) -> bool
{
    RequestWorker worker;
    auto lock = worker.Run();

    return true;
};
} // namespace OnlineSearch::Request