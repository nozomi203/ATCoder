#pragma once

#include <cassert>
#include <concepts>
#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>

#include "util/bit.h"

namespace util {

template <class S, S SIdentity, auto OpFunc>
class segment_tree {
 public:
  static_assert(
      std::is_convertible_v<decltype(OpFunc), std::function<S(S, S)>>);

 public:
  segment_tree(uint32_t n) : segment_tree(std::vector<S>(n, SIdentity)) {}
  segment_tree(uint32_t n, S&& value)
      : segment_tree(std::vector<S>(n, value)) {}
  segment_tree(uint32_t n, const S& value)
      : segment_tree(std::vector<S>(n, value)) {}
  segment_tree(const std::vector<S>& values)
      : m_n(values.size()), m_data((bit_ceil(values.size()) << 1)) {
    for (size_t i = 0; i < values.size(); ++i) {
      m_data[m_n + i] = values[i];
    }
    for (size_t i = m_n - 1; i >= 1; --i) {
      m_data[i] = OpFunc(m_data[(i << 1) + 0], m_data[(i << 1) + 1]);
    }
  }

  /// @brief gets the size of leaf
  /// @return
  size_t leaf_size() const { return m_n; }

  void apply(size_t idx, S value) {
    assert(idx < m_n);
    auto data_idx = idx + m_n;
    m_data[data_idx] = value;
    while (data_idx > 1) {
      data_idx >>= 1;
      m_data[data_idx] =
          OpFunc(m_data[(data_idx << 1) + 0], m_data[(data_idx << 1) + 1]);
    }
  }

  S query(size_t idx_l, size_t idx_r) const {
    assert(idx_l < idx_r);
    assert(idx_r <= m_n);
    auto data_idx_l = idx_l + m_n;
    auto data_idx_r = idx_r + m_n;
    S val_l(SIdentity), val_r(SIdentity);
    for (; data_idx_l < data_idx_r; data_idx_l >>= 1, data_idx_r >>= 1) {
      if (data_idx_l & 1) val_l = OpFunc(val_l, m_data[data_idx_l++]);
      if (data_idx_r & 1) val_r = OpFunc(m_data[--data_idx_r], val_r);
    }
    return OpFunc(val_l, val_r);
  }

 private:
  size_t m_n;
  std::vector<S> m_data;
};
}  // namespace util