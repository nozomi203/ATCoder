#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s32 N, S;
    cin >> N >> S;
    s32 ans = 0;
    for (s32 r = 1; r <= N; ++r)
    {
        for (s32 b = 1; b <= N; ++b)
        {
            if (r + b <= S)
            {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}