#include <cassert>
#include <concepts>
#include <cstdint>
#include <vector>

namespace util {
class union_find_tree {
 public:
  using parent_or_size_type = std::make_signed_t<size_t>;

 public:
  union_find_tree(size_t n) : m_parent_or_size(n, -1) {}

 public:
  size_t unite(size_t idx0, size_t idx1) {
    assert(idx0 < m_parent_or_size.size());
    assert(idx1 < m_parent_or_size.size());
    size_t l0 = leader(idx0), l1 = leader(idx1);
    if (l0 == l1) return l0;
    if (l0 > l1) std::swap(l0, l1);
    m_parent_or_size[l0] += m_parent_or_size[l1];
    m_parent_or_size[l1] = l0;
    return l0;
  }
  size_t leader(size_t idx) {
    assert(idx < m_parent_or_size.size());
    if (m_parent_or_size[idx] < 0) return idx;
    return m_parent_or_size[idx] = leader(m_parent_or_size[idx]);
  }
  bool same(size_t idx0, size_t idx1) {
    assert(idx0 < m_parent_or_size.size());
    assert(idx1 < m_parent_or_size.size());
    return leader(idx0) == leader(idx1);
  }

  size_t union_size(size_t idx) {
    assert(idx < m_parent_or_size.size());
    return -m_parent_or_size[leader(idx)];
  }

 private:
  std::vector<parent_or_size_type> m_parent_or_size;
};
}  // namespace util