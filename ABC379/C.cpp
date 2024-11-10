#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, M;
    cin >> N >> M;
    vector<pair<s64/*idx*/, s64/*cnt*/>> cnts(M);
    for (s64 m = 0; m < M; ++m)
    {
        cin >> cnts[m].first;
    }
    for (s64 m = 0; m < M; ++m)
    {
        cin >> cnts[m].second;
    }
    // 位置の降順にソート
    sort(cnts.begin(), cnts.end(), [](const auto& l, const auto& r) { return l.first > r.first;});
    s64 ans = 0;
    s64 last = N;
    for (const auto& cnt : cnts)
    {
        s64 diff = last - cnt.first;
        // 持ち越し
        if (diff + 1 >= cnt.second)
        {
            last -= cnt.second;
            ans += cnt.second * (2 * diff - cnt.second + 1) / 2;
        }
        // 過剰
        else {
            cout << -1 << endl;
            return 0;
        }
    }

    if (last > 0)
    {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
}