#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

u64 bits_count(u64 v)
{
    v = (v & 0x5555555555555555) + (v >> 1 & 0x5555555555555555);
    v = (v & 0x3333333333333333) + (v >> 2 & 0x3333333333333333);
    v = (v & 0x0f0f0f0f0f0f0f0f) + (v >> 4 & 0x0f0f0f0f0f0f0f0f);
    v = (v & 0x00ff00ff00ff00ff) + (v >> 8 & 0x00ff00ff00ff00ff);
    v = (v & 0x0000ffff0000ffff) + (v >> 16 & 0x0000ffff0000ffff);
    v = (v & 0x00000000ffffffff) + (v >> 32 & 0x00000000ffffffff);
    return v;
}

int main()
{
    string S;
    cin >> S;

    const u64 len = S.size();

    s64 Q;
    cin >> Q;
    for (s64 q = 0;q < Q; ++q)
    {
        u64 K;
        cin >> K;
        --K;
        const u64 strIdx = K / len;
        const u64 charIdx = K % len;
        bool bInv = (bits_count(strIdx) % 2) > 0;
        char c = S[charIdx];
        if (bInv)
        {
            c = islower(c) ? toupper(c) : tolower(c);
        }
        cout << c << " ";
    }
    cout << endl;
}