#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, X, Y;
    cin >> N >> X >> Y;
    cout << N / X + N / Y - N / lcm(X, Y);
}