#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, M;
    cin >> N >> M;
    atcoder::dsu dsu(N + 1);
    vector<s64> connCnt(N + 1, 0);
    for (s64 m = 0; m < M; ++m)
    {
        s64 A, B;
        cin >> A >> B;
        if (++connCnt[A] > 2 || ++connCnt[B] > 2)
        {
            cout << "No" << endl;
            return 0;
        }
        if (dsu.same(A, B))
        {
            cout << "No" << endl;
            return 0;
        }
        dsu.merge(A, B);
    }
    cout << "Yes" << endl;
}