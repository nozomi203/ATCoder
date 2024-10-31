#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    u64 N;
    cin >> N;
    u64 lcm;
    cin >> lcm;
    for (u64 n = 1; n < N; ++n)
    {
        u64 a;
        cin >> a;
        lcm = std::lcm(lcm, a);
    }

    cout << lcm << endl;
}