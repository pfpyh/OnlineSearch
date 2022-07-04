#include "request/Requester.hpp"

#include "types/ConnectionInfo.hpp"
#include "types/SearchResult.hpp"

#if defined(__ENABLE_TEST_CODE__)
#include <Windows.h>
#include <random>
#endif

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

auto Requester::search_async(std::string input, 
                             std::function<void()> prework,
                             std::function<void(std::vector<Types::SearchResult>&&)> postwork) -> bool
{
    _t_pool.add_work([prework, postwork]()->bool {
#if defined(__ENABLE_TEST_CODE__)
        prework();

        Sleep(100);

        // 일부로 지연을 발생시키기 위한 난수 생성
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int32_t> dis(5000, 10000);
        const int32_t delay = dis(gen);

        std::vector<Types::SearchResult> results;
        {
            Types::SearchResult result;
            result._result = "Temp" + std::to_string(delay);
            results.push_back(std::move(result));
        }

        // 강제 지연
        Sleep(delay);

        postwork(std::move(results));
#endif
        return true;
    });
    return true;
};
} // namespace OnlineSearch::Request