#include "request/Requester.hpp"

#include "types/ConnectionInfo.hpp"
#include "types/SearchResult.hpp"

#if defined(__ENABLE_TEST_CODE__)
#include <Windows.h>
#include <random>
#include <iostream>
#endif

namespace OnlineSearch::Request
{
auto Requester::connect(const Types::ConnectionInfo& info) -> bool
{
    _activated = true;
    return true;
};

auto Requester::disconnect() -> void
{
    _activated = false;
    if (_last_request)
        _last_request->get_future().wait();
};

auto Requester::search_async(std::string input, 
                             std::function<void()> prework,
                             std::function<void(std::vector<Types::SearchResult>&&)> postwork) -> bool
{
    if (!_activated) return false;

    _last_request = _t_pool.add_work([prework, postwork, input]() {
#if defined(__ENABLE_TEST_CODE__)
        prework();

        // �Ϻη� ������ �߻���Ű�� ���� ���� ����
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int32_t> dis(500, 1200);
        const int32_t delay = dis(gen);

        // ���� ����
        Sleep(delay);

        std::vector<Types::SearchResult> results;
        {
            Types::SearchResult result;
            result._result = input;
            results.push_back(std::move(result));
        }

        postwork(std::move(results));
#endif
    });
    return true;
};
} // namespace OnlineSearch::Request