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

    struct Node
    {
        vector<s64> childNodeIdxs;
        s64 connectionCnt{ 0 };
        s64 ans{ 0 };
        s64 edgeCnt{ 0 };
        bool opened{ false };
    };
    vector<Node> nodes(N + 1);
    for (s64 n = 1; n < N; ++n)
    {
        s64 u, v;
        cin >> u >> v;
        nodes[u].childNodeIdxs.push_back(v);
        nodes[v].childNodeIdxs.push_back(u);
        nodes[u].connectionCnt++;
        nodes[v].connectionCnt++;
    }

    s64 rootNodeIdx{ -1 };
    for (s64 n = 1; n <= N; ++n)
    {
        // 適当に末端のノードをルートにする
        if (nodes[n].childNodeIdxs.size() == 1)
        {
            rootNodeIdx = n;
            break;
        }
    }
    {
        struct Work {
            s64 prevNodeIdx{ -1 };
            s64 currNodeIdx{ -1 };
        };
        stack<Work> works;
        works.push({ -1, rootNodeIdx });
        while (!works.empty())
        {
            const auto [prevNodeIdx, currNodeIdx] = works.top();
            works.pop();
            Node& currNode = nodes[currNodeIdx];
            for (auto childNodeIdxItr = currNode.childNodeIdxs.begin(); childNodeIdxItr != currNode.childNodeIdxs.end();)
            {
                if (*childNodeIdxItr == prevNodeIdx)
                {
                    childNodeIdxItr = currNode.childNodeIdxs.erase(childNodeIdxItr);
                }
                else {
                    works.push({ currNodeIdx, *childNodeIdxItr });
                    ++childNodeIdxItr;
                }
            }
        }
    }

    stack<s64> activeNodeIdxs;
    activeNodeIdxs.push(rootNodeIdx);
    while (!activeNodeIdxs.empty())
    {
        s64 currNodeIdx = activeNodeIdxs.top();
        Node& currNode = nodes[currNodeIdx];
        if (currNode.opened)
        {
            for (s64 childNodeIdx : currNode.childNodeIdxs)
            {
                currNode.ans += nodes[childNodeIdx].ans;
            }

            const s64 connectionCnt = currNode.connectionCnt;
            if (connectionCnt == 3)
            {
                Node& childNode0 = nodes[currNode.childNodeIdxs[0]];
                Node& childNode1 = nodes[currNode.childNodeIdxs[1]];
                currNode.edgeCnt += childNode0.edgeCnt;
                currNode.edgeCnt += childNode1.edgeCnt;
                currNode.ans += childNode0.edgeCnt * childNode1.edgeCnt;
            }
            else if (connectionCnt == 2)
            {
                currNode.edgeCnt = 1;
                Node& childNode = nodes[currNode.childNodeIdxs[0]];
                if (childNode.connectionCnt == 3) {
                    currNode.ans += childNode.edgeCnt;
                }
            }

            activeNodeIdxs.pop();
            continue;
        }

        currNode.opened = true;

        for (auto childNodeIdx : currNode.childNodeIdxs)
        {
            activeNodeIdxs.push(childNodeIdx);
        }
    }

    cout << nodes[rootNodeIdx].ans << endl;
}