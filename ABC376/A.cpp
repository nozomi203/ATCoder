#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main()
{
    int N, C;
    cin >> N >> C;
    u32 ans = 0;
    s32 prevT = -2000;
    for (u32 i = 0; i < N; ++i)
    {
        s32 T;
        cin >> T;
        if (T - prevT >= C)
        {
            prevT = T;
            ++ans;
        }
    }
    cout << ans << endl;
}