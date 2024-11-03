#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

// nodeに接続しているノードの深さの最大を得る
pair<s64 /* インデックス */, s64 /* 深さ */> FindDeepestNode(vector<vector<s64>> &nodes, s64 nodeIdx)
{
    s64 depth = 0;
    s64 deepestNodeIdx = -1;
    stack<tuple<s64 /* prevNodeIdx */, s64 /* nodeIdx */, s64 /* depth */>> s;
    s.push({-1, nodeIdx, 0});
    while (!s.empty())
    {
        auto [prevNodeIdx, currNodeIdx, currDepth] = s.top();
        s.pop();

        if (currNodeIdx != nodeIdx && nodes[currNodeIdx].size() == 1)
        {
            if (currDepth >= depth)
            {
                depth = currDepth;
                deepestNodeIdx = currNodeIdx;
            }
            continue;
        }
        for (s64 nextNodeIdx : nodes[currNodeIdx])
        {
            if (nextNodeIdx == prevNodeIdx)
            {
                continue;
            }
            s.push({currNodeIdx, nextNodeIdx, currDepth + 1});
        }
    }

    return {deepestNodeIdx, depth};
}

int main()
{
    s64 N;
    cin >> N;
    vector<vector<s64>> nodes(N + 1);
    for (s64 n = 1; n <= N - 1; ++n)
    {
        s64 A, B;
        cin >> A >> B;
        nodes[A].emplace_back(B);
        nodes[B].emplace_back(A);
    }
    auto [idx0, depth0] = FindDeepestNode(nodes, 1);
    auto [idx1, depth1] = FindDeepestNode(nodes, idx0);
    cout << depth1 + 1 << endl;
}