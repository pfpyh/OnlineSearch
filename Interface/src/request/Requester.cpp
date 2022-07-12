#include "request/Requester.hpp"
#include "request/MySql.hpp"

#include "types/ConnectionInfo.hpp"
#include "types/SearchResult.hpp"

namespace OnlineSearch::Request
{
class PoiQuery : public MySql::Fetch<PoiQuery, std::string, std::string, std::string, std::string>
{
protected :
    std::string _input;

protected :
    auto _get_query() -> std::string
    {
        return "SELECT poiName, old_addr, new_addr, phone FROM poiTable;";
    };
};

auto Requester::connect(const Types::ConnectionInfo& info) -> bool
{
    _activated = true;
    return true;
};

auto Requester::disconnect() -> void
{
    _activated = false;
    _t_pool.wait_finish().wait();
};

auto Requester::search_async(std::string input, 
                             std::function<void()> prework,
                             std::function<void(std::vector<Types::SearchResult>&&)> postwork) -> bool
{
    if (!_activated) return false;

    _futures.push_back(std::move(_t_pool.add_work([prework, postwork, input]() {
        prework();

        std::vector<Types::SearchResult> results;

        PoiQuery query;
        if (query.connect())
        {
            if (query.exec())
            {
                std::tuple<std::string, std::string, std::string, std::string> tuple;
                while (query.fetch(std::move(tuple)))
                {
                    Types::SearchResult result;
                    result._result = std::get<0>(tuple);
                    results.push_back(std::move(result));
                }
            }
            query.disconnect();
        }

        postwork(std::move(results));
    })->get_future()));
    return true;
};
} // namespace OnlineSearch::Request