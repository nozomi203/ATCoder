#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, Q;
    cin >> N >> Q;

    struct Group
    {
        s64 beginIdx;
        s64 endIdx;
        s64 color;
    };
    vector<Group>  groups(N + 2);
    for (s64 i = 0; i <= N + 1; ++i)
    {
        groups[i].beginIdx = i;
        groups[i].endIdx = i + 1;
        groups[i].color = i;
    }
    vector<s64> counts(N + 2, 1); // 色数
    atcoder::dsu dsu(N + 2);

    vector<s64> answers;
    for (s64 q = 0; q < Q; ++q)
    {
        s64 query;
        cin >> query;
        if (query == 1)
        {
            s64 x, c;
            cin >> x >> c;
            s64 currGroupIdx = dsu.leader(x);
            s64 prevGroupIdx = dsu.leader(groups[currGroupIdx].beginIdx - 1);
            s64 nextGroupIdx = dsu.leader(groups[currGroupIdx].endIdx);
            s64 cnt = groups[currGroupIdx].endIdx - groups[currGroupIdx].beginIdx;
            counts[groups[currGroupIdx].color] -= cnt;
            counts[c] += cnt;
            groups[currGroupIdx].color = c;
            s64 newBeginIdx = groups[currGroupIdx].beginIdx;
            s64 newEndIdx = groups[currGroupIdx].endIdx;
            if (groups[nextGroupIdx].color == c)
            {
                newEndIdx = groups[nextGroupIdx].endIdx;
                dsu.merge(currGroupIdx, nextGroupIdx);
            }
            if (groups[prevGroupIdx].color == c)
            {
                newBeginIdx = groups[prevGroupIdx].beginIdx;
                dsu.merge(prevGroupIdx, currGroupIdx);
            }
            s64 newGroupIdx = dsu.leader(currGroupIdx);
            groups[newGroupIdx].beginIdx = newBeginIdx;
            groups[newGroupIdx].endIdx = newEndIdx;
        }
        else
        {
            s64 c;
            cin >> c;
            answers.emplace_back(counts[c]);
        }
    }

    for (auto ans : answers)
    {
        cout << ans << endl;
    }
}