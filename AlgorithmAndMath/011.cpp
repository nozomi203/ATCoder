#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

void ForeachPrime(s32 max, function<void(s32)> func)
{
    vector<bool> p(max + 1, true);

    for (s32 n = 2; n <= max; ++n)
    {
        if (!p[n])
        {
            continue;
        }
        s32 mul = n * 2; // 倍数
        while (mul <= max)
        {
            p[mul] = false;
            mul += n;
        }
    }

    for (s32 n = 2; n <= max; ++n)
    {
        if (p[n])
        {
            func(n);
        }
    }
}

int main()
{
    s32 N;
    cin >> N;

    ForeachPrime(N, [](s32 prime)
                 { cout << prime << " "; });
    cout << endl;
}