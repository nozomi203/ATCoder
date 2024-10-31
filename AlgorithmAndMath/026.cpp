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
    double ans = 0;
    for (int n = N; n >= 1; --n)
    {
        ans += static_cast<double>(N) / n;
    }
    cout << fixed << setprecision(20) << ans << endl;
}