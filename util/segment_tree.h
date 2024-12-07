#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>

#include "util/bit_op.h"

namespace util {

template <class T>
class segment_tree {
 public:
  segment_tree(uint32_t n, T identity, std::function<T(T, T)> op)
      : m_n(n),
        m_identity(identity),
        m_buffer((bit_ceil(n) << 1) - 1, identity),
        m_op(op) {}

  /// @brief gets the size of internal buffer
  size_t buffer_size() const { return m_buffer.size(); }

  /// @brief gets the size of leaf
  /// @return
  size_t leaf_size() const { return m_n; }

  /// @brief update value at [idx] by [value]
  /// @param idx 0 <= idx < n
  /// @param value
  void update(uint32_t idx, T value) {
    assert(0 <= idx && idx < m_n);
    idx += m_n;
    m_buffer[idx - 1] = value;
    while (idx > 1) {
      idx = idx >> 1;
      m_buffer[idx - 1] = m_op(m_buffer[idx * 2 - 1], m_buffer[idx * 2]);
    }
  }

  /// @brief get the result of op in segment [idx_l, idx_r)
  /// @param idx_l should be < idx_r
  /// @param idx_r should be idx_r <= m_n
  /// @return
  T query(uint32_t idx_l, uint32_t idx_r) const {
    assert(idx_l < idx_r);
    assert(idx_r <= m_n);
    idx_l += m_n;
    idx_r += m_n;
    T v_l(m_identity), v_r(m_identity);
    for (; idx_l < idx_r; idx_l >>= 1, idx_r >>= 1) {
      if (idx_l & 1) v_l = m_op(v_l, m_buffer[(idx_l++) - 1]);
      if (idx_r & 1) v_r = m_op(m_buffer[(--idx_r) - 1], v_r);
    }
    return m_op(v_l, v_r);
  }

 private:
  uint32_t m_n;
  T m_identity;
  std::vector<T> m_buffer;
  std::function<T(T, T)> m_op;
};
}  // namespace util