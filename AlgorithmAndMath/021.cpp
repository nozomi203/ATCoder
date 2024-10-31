#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

s64 factorial(s64 n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    s64 n, r;
    cin >> n >> r;

    cout << (factorial(n) / factorial(r)) / factorial(n - r);
}