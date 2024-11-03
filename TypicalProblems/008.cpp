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
    cin >> N;
    string S;
    cin >> S;

    constexpr s64 kMod = 1000000007;
    const string atcoder = "atcoder";
    // dp[n][i] = Sのn文字目までの中から文字を取り出したとき、その文字列が"atcoder"のi文字目までになっている場合の数
    vector<vector<s64>> dp(N + 1, vector<s64>(atcoder.size() + 1, 0));
    for (s64 n = 0; n <= N; ++n)
    {
        dp[n][0] = 1;
    }
    for (s64 n = 1; n <= N; ++n)
    {
        for (s64 i = 1; i <= atcoder.size(); ++i)
        {
            dp[n][i] += dp[n - 1][i];
            if (S[n - 1] == atcoder[i - 1])
            {
                dp[n][i] += dp[n - 1][i - 1];
            }
            dp[n][i] %= kMod;
        }
    }

    cout << dp[N][atcoder.size()] << endl;

}