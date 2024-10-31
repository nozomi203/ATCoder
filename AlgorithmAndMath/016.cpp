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
    vector<u64> A(N);
    cin >> A[0];
    u64 gcd = A[0];
    for (u64 n = 1; n < N; ++n)
    {
        cin >> A[n];
        gcd = std::gcd(gcd, A[n]);
    }
    cout << gcd << endl;
}