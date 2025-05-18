#pragma once

#include <queue>
#include <vector>

namespace util {

/// @brief 与えられたグラフをトロポジカルソートした結果を返す
/// @param g グラフ
/// @return {トポロジカルソートの結果を示すフラグ、ソート結果}
std::pair<bool, std::vector<size_t>> topological_sort(
    const std::vector<std::vector<size_t>>& g) {
  std::vector<size_t> ins(g.size());
  for (const auto& tos : g) {
    for (size_t to : tos) {
      ++ins[to];
    }
  }

  std::queue<size_t> q;
  for (size_t i{0}; i < g.size(); ++i) {
    if (ins[i] == 0) {
      q.push(i);
    }
  }

  std::vector<size_t> ret;
  ret.reserve(g.size());
  while (!q.empty()) {
    const auto n{q.front()};
    q.pop();

    for (const auto to : g[n]) {
      if (--ins[to] == 0) {
        q.push(to);
      }
    }

    ret.push_back(n);
  }

  return {ret.size() == g.size(), std::move(ret)};
}
}  // namespace util