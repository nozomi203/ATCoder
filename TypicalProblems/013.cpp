#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

struct Edge
{
    s64 to{ -1 };
    s64 cost{ 0 };
};

vector<s64> Dijkstra(const vector<vector<Edge>>& graph, s64 startIdx)
{
    vector<s64> distances(graph.size(), std::numeric_limits<s64>::max());
    using pair = std::pair<s64, s64>;
    std::priority_queue < pair, std::vector<pair>, std::greater <pair>> q;
    distances[startIdx] = 0;
    q.push({ 0, startIdx });
    while (!q.empty())
    {
        auto [dist, idx] = q.top();
        q.pop(); // 確定

        if (dist > distances[idx])
        {
            continue;
        }

        for (const Edge& e : graph[idx])
        {
            s64 newDist = distances[idx] + e.cost;
            if (newDist < distances[e.to])
            {
                distances[e.to] = newDist;
                q.push({ newDist, e.to });
            }
        }
    }

    return distances;
}

int main()
{
    s64 N, M;
    cin >> N >> M;
    vector<vector<Edge>> graph(N + 1);
    for (s64 m = 1; m <= M; ++m)
    {
        s64 A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back(Edge{ B, C });
        graph[B].push_back(Edge{ A, C });
    }
    const auto distancesFrom1 = Dijkstra(graph, 1);
    const auto distancesFromN = Dijkstra(graph, N);
    for (s64 k = 1; k <= N; ++k)
    {
        cout << distancesFrom1[k] + distancesFromN[k] << endl;
    }
}