#pragma once
#include <cassert>
#include <cstdint>
#include <limits>
#include <queue>
#include <vector>

namespace util {
inline std::pair<bool, std::vector<std::size_t>> bipartition(
    const std::vector<std::vector<std::size_t>>& g) {
  constexpr std::size_t inf = std::numeric_limits<std::size_t>::max();
  assert(g.size() < inf);
  assert(!g.empty());
  std::vector<std::size_t> ret(g.size(), inf);

  std::queue<std::size_t> q;
  q.push(0);
  ret[0] = 0;
  while (!q.empty()) {
    const auto cur{q.front()};
    q.pop();
    for (const auto nxt : g[cur]) {
      if (ret[nxt] == inf) {
        q.push(nxt);
        ret[nxt] = (ret[cur] + 1) % 2;
      } else if (ret[nxt] != ret[cur]) {
        continue;
      } else {
        return {false, ret};
      }
    }
  }
  return {true, ret};
}
}  // namespace util