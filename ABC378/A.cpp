#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    array<s64, 5> cnts{};
    for (s64 n = 0; n < 4; ++n)
    {
        s64 A;
        cin >> A;
        cnts[A]++;
    }
    s64 ans = 0;
    for (auto cnt : cnts)
    {
        ans += cnt / 2;
    }
    cout << ans << endl;
}