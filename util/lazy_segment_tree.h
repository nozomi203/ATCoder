#include <bit>
#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <optional>
#include <stack>
#include <vector>

#include "util/bit_op.h"

namespace util {

template <class T>
class lazy_segment_tree {
 public:
  lazy_segment_tree(uint32_t n, T identity, std::function<T(T, T)> op)
      : m_n(n),
        m_depth_max(std::countr_zero(bit_ceil(n))),
        m_identity(identity),
        m_buffer((bit_ceil(n) << 1) - 1, identity),
        m_lazy(bit_ceil(n) - 1, identity),
        m_op(op) {}

  /// @brief gets the size of internal buffer
  size_t buffer_size() const { return m_buffer.size(); }

  /// @brief gets the size of leaf
  /// @return
  size_t leaf_size() const { return m_n; }

  /// @brief update value in segment [<idx_l>, <idx_r>) by <value>
  /// @param idx 0 <= idx < n
  /// @param value
  void update(uint32_t idx_l, uint32_t idx_r, T value) {
    assert(idx_l < idx_r);
    assert(idx < m_n);
    const auto buff_idx_l = idx_l + m_n;  // buffer index starts at 1
    const auto buff_idx_r = idx_r + m_n;  // buffer index starts at 1
    const auto depth_max_l = m_depth_max - std::countr_zero(buff_idx_l);
    const auto depth_max_r = m_depth_max - std::countr_zero(buff_idx_r);
    uint32_t depth = 0;
    uint32_t curr_buff_idx_l = 1;
    uint32_t curr_buff_idx_r = 1;
    while (curr_buff_idx_l == curr_buff_idx_r) {
      curr_buff_idx_l >>
    }
    uint32_t mask = 1 << m_depth_max;
    while () idx_l += m_n;
    idx_r += m_n;
    idx_l >>= std::countr_zero(idx_l);
    idx_r >>= std::countr_zero(idx_r);
    std::stack<uint32_t> idxs;
    // lとrが合流するまで
    while (idx_l < idx_r) {
      idx_l >>= 1;
      idx_r >>= 1;
      idxs.push(idx_l);
      idxs.push(idx_r);
    }
    // lとrが合流後
    while (idx_l > 1) {
      idx_l >>= 1;
      idxs.push(idx_l);
    }

    while (!idxs.empty()) {
      auto idx = idxs.top();
      idxs.pop();
      if (m_lazy[idx - 1]) {
        auto val = *m_lazy[idx - 1];
        m_lazy[idx - 1] = std::nullopt;
        m_lazy[idx * 2 - 1] = val;
        m_lazy[idx * 2] = val;
        m_buffer[idx] = m_op(m_buffer[idx], val);
      }
    }
  }

  /// @brief get the result of op in segment [idx_l, idx_r)
  /// @param idx_l should be < idx_r
  /// @param idx_r should be idx_r <= m_n
  /// @return
  T query(uint32_t idx_l, uint32_t idx_r) const {
    assert(idx_l < idx_r);
    assert(idx_r <= m_n);
    // idx_l += m_n - 1;
    // idx_r += m_n - 1;
    // T v_l(m_identity), v_r(m_identity);
    // for (; idx_l < idx_r; idx_l >>= 1, idx_r >>= 1) {
    //   if (!(idx_l & 1)) v_l = m_op(v_l, m_buffer[idx_l++]);
    //   if (!(idx_r & 1)) v_r = m_op(m_buffer[--idx_r], v_r);
    // }
    // return m_op(v_l, v_r);
  }

 private:
  uint32_t m_n;
  uint32_t m_depth_max;  // >= 0
  T m_identity;
  std::vector<T> m_buffer;
  std::vector<std::optional<T>> m_lazy;
  std::function<T(T, T)> m_op;
};
}  // namespace util