#include <bits/stdc++.h>
#include <atcoder/fenwicktree.hpp>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N;
    cin >> N;

    // dp[n] = n番目の頂点をルートとする木
    vector<s64> dp(N + 1, 0);

    struct Node
    {
        vector<s64> connectedNodeIndices;
        bool opened{ false };
    };
    vector<Node> nodes(N + 1);
    for (s64 n = 1; n < N; ++n)
    {
        s64 u, v;
        cin >> u >> v;
        nodes[u].connectedNodeIndices.push_back(v);
        nodes[v].connectedNodeIndices.push_back(u);
    }

    stack<s64> nodeIndices;
    nodeIndices.push(1);
    while (!nodeIndices.empty())
    {
        s64 currentNodeIndices = nodeIndices.top();
        Node& currentNode = nodes[currentNodeIndices];
        if (currentNode.opened)
        {
            // 帰りがけの処理
            {
            }

            nodeIndices.pop();
            continue;
        }

        currentNode.opened = true;

        for (auto connectedNodeIndex : currentNode.connectedNodeIndices)
        {
            const Node& nextNode = nodes[connectedNodeIndex];
            if (!nextNode.opened)
            {
                nodeIndices.push(connectedNodeIndex);
            }
        }
    }
}