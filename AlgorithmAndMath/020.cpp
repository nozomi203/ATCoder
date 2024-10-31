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

    // dp[n][k][p] = n枚目までのカードからk枚選んだときの合計がpになる通り
    vector<vector<vector<u64>>> dp(101, vector<vector<u64>>(6, vector<u64>(1001, 0)));
    for (s64 n = 0; n <= N; ++n)
    {
        dp[n][0][0] = 1;
    }

    for (s64 n = 1; n <= N; ++n)
    {
        s64 A;
        cin >> A;

        for (s64 k = 1; k <= 5; ++k)
        {
            for (s64 p = 1; p <= 1000; ++p)
            {
                if (n > k)
                {
                    dp[n][k][p] += dp[n - 1][k][p];
                }
                if (p >= A)
                {
                    dp[n][k][p] += dp[n - 1][k - 1][p - A];
                }
            }
        }
    }

    cout << dp[N][5][1000] << endl;
}