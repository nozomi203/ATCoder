#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, A, B, C;
    cin >> N >> A >> B >> C;
    // dp[i][j] = i枚の硬貨の合計をj円にできるか
    vector<vector<bool>> dp(10000, vector<bool>(N + 1, false));
    dp[0][0] = true;
    for (s64 i = 1; i <= 9999; ++i)
    {
    }
}