#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N;
    struct Task
    {
        s64 D{};
        s64 C{};
        s64 S{};
    };
    cin >> N;
    vector<Task> tasks(N + 1);
    for (s64 n = 1; n <= N; ++n)
    {
        cin >> tasks[n].D >> tasks[n].C >> tasks[n].S;
    }
    std::sort(tasks.begin(), tasks.end(), [](const auto &l, const auto &r)
              { return l.D < r.D; });

    // dp[i][j] = i個目までのタスクの中から取捨選択したときのj日目の報酬の最大値
    vector<vector<s64>> dp(N + 1, vector<s64>(N + 1, 0));
    for (s64 i = 1; i <= N; ++i)
    {
        for (s64 j = 1; j <= N; ++j)
        {
        }
    }
}