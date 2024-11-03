#include <bits/stdc++.h>
#include <atcoder/fenwicktree.hpp>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, M;
    cin >> N >> M;
    vector<s64> S(N + 1, 0); // Aの塁積和
    for (s64 n = 1; n <= N; ++n)
    {
        s64 A;
        cin >> A;
        S[n] = (S[n - 1] + A) % M;
    }

    atcoder::fenwick_tree<s64> ft(M);
    s64 s = 0;
    s64 ans = 0;
    for (s64 r = 1; r <= N; ++r)
    {
        ans += (r * S[r] - s + ft.sum(S[r] + 1, M) * M);
        s += S[r];
        ft.add(S[r], 1);
    }

    cout << ans << endl;
}