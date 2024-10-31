#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, W;
    cin >> N >> W;
    // dp[n][w] = n番目までの荷物の中から重さの合計がwになるように荷物を選んだときの価値の最大値
    vector<vector<s64>> dp(N + 1, vector<s64>(W + 1, 0));

    for (s64 n = 1; n <= N; ++n)
    {
        s64 wi, vi;
        cin >> wi >> vi;
        for (s64 w = 1; w <= W; ++w)
        {
            if (w >= wi)
            {
                dp[n][w] = max(dp[n - 1][w], dp[n - 1][w - wi] + vi);
            }
            else
            {
                dp[n][w] = dp[n - 1][w];
            }
        }
    }

    s64 ans = 0;
    for (s64 w = 1; w <= W; ++w)
    {
        ans = max(ans, dp[N][w]);
    }
    cout << ans << endl;
}