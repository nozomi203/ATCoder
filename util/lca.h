#pragma once
#include <vector>

#include "functional.h"
#include "sparse_table.h"

namespace util {
class lca {
 public:
  lca(const std::vector<std::vector<size_t>>& conns, size_t root)
      : m_st(std::invoke([&conns, root]() -> std::vector<size_t> {

        })) {}

 private:
  sparse_table<size_t, size_t, minimum<size_t>()> m_st;
};
}  // namespace util