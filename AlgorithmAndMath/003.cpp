#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s32 N;
    s32 ans = 0;
    cin >> N;
    for (int n = 0; n < N; ++n)
    {
        s32 A;
        cin >> A;
        ans += A;
    }
    cout << ans << endl;
}