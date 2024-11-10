#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N;
    cin >> N;
    s64 c = N % 10;
    N = (N - c) / 10;
    s64 b = N % 10;
    N = (N - b) / 10;
    s64 a = N % 10;

    cout << b * 100 + c * 10 + a << " " << c * 100 + a * 10 + b << endl;
}