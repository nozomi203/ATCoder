#pragma once
#include <limits>
#include <optional>
#include <stack>
#include <vector>

#include "functional.h"
#include "sparse_table.h"

namespace util {
class lca {
 public:
  using node_depth_pair = std::pair<size_t, size_t>;

 public:
  lca(const std::vector<std::vector<size_t>>& tree, size_t root)
      : m_first_idx(tree.size(), std::numeric_limits<size_t>::max()),
        m_st(std::invoke([&]() -> std::vector<node_depth_pair> {
          std::vector<bool> opened(tree.size(), false);
          std::vector<node_depth_pair> ndps;
          std::stack<node_depth_pair> s;
          s.push(std::make_pair(0, 0));
          while (!s.empty()) {
            const auto [node, depth] = s.top();

            const auto idx = ndps.size();
            m_first_idx[node] = std::min(m_first_idx[node], idx);
            ndps.push_back(std::make_pair(node, depth));

            if (opened[node] || tree[node].empty()) {
              s.pop();
            } else {
              for (size_t i{0}; i < tree[node].size(); ++i) {
                const auto nxt_node = tree[node][i];
                if (i > 0) s.push(std::make_pair(node, depth));
                s.push(std::make_pair(nxt_node, depth + 1));
              }
            }
            opened[node] = true;
          }
          return ndps;
        })) {}

 public:
  size_t query(size_t n0, size_t n1) const {
    const auto idx_l = std::min(m_first_idx[n0], m_first_idx[n1]);
    const auto idx_r = std::max(m_first_idx[n0], m_first_idx[n1]);
    return m_st.query(idx_l, idx_r).first;
  }

 private:
  std::vector<size_t> m_first_idx;
  sparse_table<node_depth_pair,
               [](const node_depth_pair& l, const node_depth_pair& r) {
                 return l.second < r.second ? l : r;
               }>
      m_st;
};
}  // namespace util