#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

s64 dfs(s64 l, s64 r, vector<s64> &a, vector<vector<s64>> &dp)
{
    if (dp[l][r] != numeric_limits<s64>::lowest())
    {
        return dp[l][r];
    }

    if (l == r)
    {
        return dp[l][r] = 0;
    }

    s64 ret = numeric_limits<s64>::lowest();
    ret = max(ret, -dfs(l + 1, r, a, dp) + a[l]);
    ret = max(ret, -dfs(l, r - 1, a, dp) + a[r - 1]);
    return dp[l][r] = ret;
}

int main()
{
    s64 N;
    cin >> N;
    vector<s64> a(N + 1);
    for (s64 i = 1; i <= N; ++i)
    {
        cin >> a[i];
    }
    vector<vector<s64>> dp(N + 2, vector<s64>(N + 2, numeric_limits<s64>::lowest())); // dp[i][j] = aの区間[i, j)が残っているときの得点の最大
    cout << dfs(1, N + 1, a, dp) << endl;
}