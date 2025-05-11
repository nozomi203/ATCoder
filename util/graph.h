#pragma once
#include <concepts>
#include <cstdint>
#include <limits>
#include <queue>
#include <vector>
namespace util {
class graph {
 public:
  graph(size_t n) : m_neighbors(n) {}

 public:
  void add_edge(size_t from, size_t to) { m_neighbors[from].push_back(to); }

  const std::vector<std::vector<size_t>>& get_neighbors() const {
    return m_neighbors;
  }
  const std::vector<size_t>& get_neighbors(size_t from) const {
    return m_neighbors[from];
  }

 private:
  std::vector<std::vector<size_t>> m_neighbors;
};

}  // namespace util