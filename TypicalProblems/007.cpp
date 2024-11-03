#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N;
    cin >> N;
    vector<s64> A(N);
    for (s64 n = 0; n < N; ++n)
    {
        cin >> A[n];
    }
    s64 Q;
    cin >> Q;
    vector<s64> B(Q);
    for (s64 q = 0; q < Q; ++q)
    {
        cin >> B[q];
    }

    sort(A.begin(), A.end());

    for (s64 b : B)
    {
        auto itr = upper_bound(A.begin(), A.end(), b);
        if (itr == A.end())
        {
            cout << abs(A.back() - b) << endl;
        }
        else if (itr == A.begin())
        {
            cout << abs(A.front() - b) << endl;
        }
        else {
            cout << min(abs(*itr - b), abs(*prev(itr) - b)) << endl;
        }
    }
}