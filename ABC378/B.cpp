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
    vector<s64> q(N + 1);
    vector<s64> r(N + 1);
    for (s64 n = 1; n <= N; ++n)
    {
        cin >> q[n] >> r[n];
    }
    s64 Q;
    cin >> Q;
    vector<s64> answers(Q + 1);
    for (s64 i = 1; i <= Q; ++i)
    {
        s64 t, d;
        cin >> t >> d;
        s64 rem = d % q[t];
        answers[i] = rem > r[t] ? d + r[t] + q[t] - rem : d + r[t] - rem;
    }

    for (s64 i = 1; i <= Q; ++i)
    {
        cout << answers[i] << endl;
    }
}