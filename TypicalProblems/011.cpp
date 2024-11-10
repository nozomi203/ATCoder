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
    s64 maxD{ 0 };
    for (s64 n = 1; n <= N; ++n)
    {
        cin >> tasks[n].D >> tasks[n].C >> tasks[n].S;
        maxD = max(maxD, tasks[n].D);
    }
    std::sort(tasks.begin(), tasks.end(), [](const auto& l, const auto& r)
        { return l.D < r.D; });

    // dp[i][j] = i個目までの仕事を見たときのj日目に得られる報酬の最大値
    vector<vector<s64>> dp(N + 1, vector<s64>(maxD + 1, 0));
    for (s64 i = 1; i <= N; ++i)
    {
        Task& task = tasks[i];
        for (s64 j = 1; j <= maxD; ++j)
        {
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
            s64 jNext = j + task.C;
            if (jNext <= task.D)
            {
                dp[i][jNext] = std::max(dp[i][jNext], dp[i - 1][j] + task.S);
            }
        }
    }
    s64 ans = 0;
    for (s64 val : dp[N])
    {
        ans = std::max(ans, val);
    }
    cout << ans << endl;
}