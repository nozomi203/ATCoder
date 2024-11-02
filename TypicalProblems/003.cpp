#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

struct Edge
{
    s64 nodeIdx{-1}; // 接続先のノードのインデックス
    s64 depth{-1};   // 接続先のノード以降の最大深さ
};

struct Node
{
    vector<Edge> edges;
};

int main()
{
    s64 N;
    cin >> N;
    vector<Node> nodes(N);
    for (s64 n = 0; n < N; ++n)
    {
        s64 A, B;
        cin >> A >> B;
        nodes[A].edges.emplace_back(Edge{B, -1});
        nodes[B].edges.emplace_back(Edge{A, -1});
    }
}