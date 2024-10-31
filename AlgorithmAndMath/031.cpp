#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N;
    cin >> N;
    // dp[n][b] = n日目の時点でやる気b(0=なし、1=あり)の時の実力の最大値
    vector<vector<s64>> dp(N + 1, vector<s64>(2, 0));
    for (s64 n = 1; n <= N; ++n)
    {
        s64 A;
        cin >> A;
        dp[n][0] = dp[n - 1][1] + A;
        dp[n][1] = max(dp[n - 1][1], dp[n - 1][0]);
    }

    cout << max(dp[N][0], dp[N][1]) << endl;
}