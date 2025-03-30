#pragma once
#include <cstdint>
#include <limits>
#include <queue>
#include <vector>
namespace util {
inline void graph2tree(std::vector<std::vector<int64_t>>& graph, int64_t root) {
  std::vector<bool> opened(graph.size(), false);
  std::queue<int64_t> q;
  q.push(root);
  while (!q.empty()) {
    auto idx = q.front();
    q.pop();

    opened[idx] = true;
    for (auto it = graph[idx].begin(); it != graph[idx].end();) {
      if (opened[*it]) {
        it = graph[idx].erase(it);
      } else {
        q.push(*it);
        ++it;
      }
    }
  }
}

}  // namespace util