#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, K;
    cin >> N >> K;
    vector<s64> a(N + 1);
    for (s64 n = 1; n <= N; ++n) cin >> a[n];
    vector<bool> dp(K + 1, false); // dp[i] = 山に石がi個ある曲面は勝ち？
    for (s64 i = 1; i <= K; ++i)
    {
        for (s64 j = 1; j <= N; ++j)
        {
            if (i - a[j] >= 0)
            {
                dp[i] = dp[i] || !dp[i - a[j]];
            }
        }
    }

    cout << (dp[K] ? "First" : "Second") << endl;
}