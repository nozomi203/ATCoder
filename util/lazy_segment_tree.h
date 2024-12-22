#include <bit>
#include <cassert>
#include <concepts>
#include <cstdint>
#include <functional>
#include <iostream>
#include <optional>
#include <stack>
#include <vector>

#include "util/bit_op.h"
#include "util/concepts.h"

namespace util {
template <class S, class F, S SIdentity, F FIdentity, auto OpFunc,
          auto MappingFunc, auto CompositionFunc>
class lazy_segment_tree {
  static_assert(
      std::is_convertible_v<decltype(OpFunc), std::function<S(S, S)>>);
  static_assert(
      std::is_convertible_v<decltype(MappingFunc), std::function<S(F, S)>>);
  static_assert(
      std::is_convertible_v<decltype(CompositionFunc), std::function<F(F, F)>>);

 public:
  lazy_segment_tree(size_t n) : lazy_segment_tree(std::vector(n, SIdentity)) {}
  lazy_segment_tree(const std::vector<S>& values)
      : m_n(values.size()),
        m_depth_max(std::countr_zero(bit_ceil(values.size()))),
        m_data((bit_ceil(values.size()) << 1)),
        m_lazy(bit_ceil(values.size()), FIdentity) {
    for (size_t i = 0; i < values.size(); ++i) {
      m_data[m_n + i] = values[i];
    }
    for (size_t i = m_n - 1; i >= 1; --i) {
      m_data[i] = OpFunc(m_data[(i << 1) + 0], m_data[(i << 1) + 1]);
    }
  }

  size_t leaf_size() const { return m_n; }

  void apply(size_t idx_l, size_t idx_r, F f) {
    assert(idx_l < idx_r);
    assert(idx_r <= m_n);
    const auto data_idx_l = idx_l + m_n;
    const auto data_idx_r = idx_r + m_n;

    for (uint32_t depth = m_depth_max; depth >= 1; --depth) {
      const size_t mask = (1 << depth) - 1;
      if (data_idx_l & mask) distribute_lazy(data_idx_l >> depth);
      if (data_idx_r & mask) distribute_lazy((data_idx_r - 1) >> depth);
    }

    {
      auto data_idx_l_tmp = data_idx_l;
      auto data_idx_r_tmp = data_idx_r;
      for (; data_idx_l_tmp < data_idx_r_tmp;
           data_idx_l_tmp >>= 1, data_idx_r_tmp >>= 1) {
        if (data_idx_l_tmp & 1) apply(data_idx_l_tmp++, f);
        if (data_idx_r_tmp & 1) apply(--data_idx_r_tmp, f);
      }
    }

    for (uint32_t depth = 1; depth <= m_depth_max; ++depth) {
      const size_t mask = (1 << depth) - 1;
      if (data_idx_l & mask) collect_data(data_idx_l >> depth);
      if (data_idx_r & mask) collect_data((data_idx_r - 1) >> depth);
    }
  }

  S query(size_t idx_l, size_t idx_r) {
    assert(idx_l < idx_r);
    assert(idx_r <= m_n);
    auto data_idx_l = idx_l + m_n;
    auto data_idx_r = idx_r + m_n;
    for (uint32_t depth = m_depth_max; depth >= 1; --depth) {
      const size_t mask = (1 << depth) - 1;
      if (data_idx_l & mask) distribute_lazy(data_idx_l >> depth);
      if (data_idx_r & mask) distribute_lazy((data_idx_r - 1) >> depth);
    }

    S value_l{SIdentity}, value_r{SIdentity};
    for (; data_idx_l < data_idx_r; data_idx_l >>= 1, data_idx_r >>= 1) {
      if (data_idx_l & 1) value_l = OpFunc(value_l, m_data[data_idx_l++]);
      if (data_idx_r & 1) value_r = OpFunc(value_r, m_data[--data_idx_r]);
    }
    return OpFunc(value_l, value_r);
  }

 private:
  void distribute_lazy(size_t data_idx) {
    apply(data_idx * 2 + 0, m_lazy[data_idx]);
    apply(data_idx * 2 + 1, m_lazy[data_idx]);
    m_lazy[data_idx] = FIdentity;
  }
  void apply(size_t data_idx, F f) {
    m_data[data_idx] = MappingFunc(f, m_data[data_idx]);
    if (data_idx < m_n) {
      m_lazy[data_idx] = CompositionFunc(f, m_lazy[data_idx]);
    }
  }
  void collect_data(size_t data_idx) {
    m_data[data_idx] =
        OpFunc(m_data[(data_idx << 1)], m_data[(data_idx << 1) + 1]);
  }

 private:
  size_t m_n;            // 要素数
  uint32_t m_depth_max;  // 木の最大深度
  std::vector<S> m_data;
  std::vector<F> m_lazy;
};
}  // namespace util