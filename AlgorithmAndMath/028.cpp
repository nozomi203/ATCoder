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

    vector<s64> h(N + 1);
    for (s64 n = 1; n <= N; ++n)
    {
        cin >> h[n];
    }

    // minCost[n] = 足場nにたどり着くまでの最小コスト
    vector<s64> minCost(N + 1, 0);
    minCost[2] = abs(h[2] - h[1]);

    for (s64 n = 3; n <= N; ++n)
    {
        minCost[n] = min(minCost[n - 2] + abs(h[n] - h[n - 2]),
                         minCost[n - 1] + abs(h[n] - h[n - 1]));
    }

    cout << minCost[N] << endl;
}