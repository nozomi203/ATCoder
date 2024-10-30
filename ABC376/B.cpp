#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;
using namespace std;

s32 GetSignedDistance(s32 h, s32 t, s32 n)
{
    s32 halfN = n / 2;
    s32 diff = t - h;
    if (diff < -halfN)
    {
        return diff + n;
    }
    else if (diff > halfN)
    {
        return diff - n;
    }
    else
    {
        return diff;
    }
}

int main()
{
    s32 N, Q;
    cin >> N >> Q;

    s32 l = 1;
    s32 r = 2;
    s32 ans = 0;
    for (u32 q = 0; q < Q; ++q)
    {
        char H;
        s32 T;
        cin >> H >> T;
        bool isL = H == 'L';
        s32 &t0 = isL ? l : r;
        s32 &t1 = isL ? r : l;

        s32 d0 = GetSignedDistance(t0, T, N);
        s32 d1 = GetSignedDistance(t1, T, N);
        bool sameSign = d0 * d1 > 0;
        s32 d0Abs = abs(d0);
        s32 d1Abs = abs(d1);
        ans += (sameSign && d0Abs > d1Abs) ? N - d0Abs : d0Abs;
        t0 = T;
    }
    cout << ans << endl;
}