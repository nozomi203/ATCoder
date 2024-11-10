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
    atcoder::fenwick_tree<s64> ft0(N + 1), ft1(N + 1);
    for (s64 i = 1; i <= N; ++i)
    {
        s64 C, P;
        cin >> C >> P;
        if (C == 1)
        {
            ft0.add(i, P);
        }
        else
        {
            ft1.add(i, P);
        }
    }

    s64 Q;
    cin >> Q;
    vector<pair<s64, s64>> answers(Q);
    for (s64 q = 0; q < Q; ++q)
    {
        s64 L, R;
        cin >> L >> R;
        answers[q].first = ft0.sum(L, R + 1);
        answers[q].second = ft1.sum(L, R + 1);
    }

    for (const auto &answer : answers)
    {
        cout << answer.first << " " << answer.second << endl;
    }
}