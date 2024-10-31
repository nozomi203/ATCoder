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

    array<s64, 100001> count{};

    s64 ans{};
    for (s64 n = 0; n < N; ++n)
    {
        s64 A;
        cin >> A;
        ans += count[100000 - A];
        count[A]++;
    }
    cout << ans << endl;
}