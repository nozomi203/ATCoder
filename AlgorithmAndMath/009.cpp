#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    // dp[n][s] = n枚目までのカードの中からいくつか選んで合計sにできるか
    array<array<bool, 10001>, 61> dp{};

    s32 N, S;
    cin >> N >> S;

    // nがいくつであろうと合計をゼロにすることはできる
    for (s32 n = 0; n <= N; ++n)
    {
        dp[n][0] = true;
    }

    for (s32 n = 1; n <= N; ++n)
    {
        s32 An;
        cin >> An;
        for (s32 s = 1; s <= S; ++s)
        {
            if (s >= An)
            {
                dp[n][s] = dp[n - 1][s - An] || dp[n - 1][s];
            }
            else
            {
                dp[n][s] = dp[n - 1][s];
            }
        }
    }

    cout << (dp[N][S] ? "Yes" : "No") << endl;
}