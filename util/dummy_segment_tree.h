#pragma once

#include <cassert>
#include <concepts>
#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>

#include "util/bit_op.h"

namespace util {

template <class S, class F, S SIdentity, auto OpFunc, auto MappingFunc,
          auto CompositionFunc>
class dummy_lazy_segment_tree {
 public:
  static_assert(
      std::is_convertible_v<decltype(OpFunc), std::function<S(S, S)>>);
  static_assert(
      std::is_convertible_v<decltype(MappingFunc), std::function<S(F, S)>>);
  static_assert(
      std::is_convertible_v<decltype(CompositionFunc), std::function<F(F, F)>>);

 public:
  dummy_lazy_segment_tree(size_t n)
      : dummy_lazy_segment_tree(std::vector<S>(n, SIdentity)) {}
  dummy_lazy_segment_tree(size_t n, S&& value)
      : dummy_lazy_segment_tree(std::vector<S>(n, value)) {}
  dummy_lazy_segment_tree(size_t n, const S& value)
      : dummy_lazy_segment_tree(std::vector<S>(n, value)) {}
  dummy_lazy_segment_tree(const std::vector<S>& values) : m_data(values) {}

  /// @brief gets the size of leaf
  /// @return
  size_t leaf_size() const { return m_data.size(); }

  void apply(size_t idx_l, size_t idx_r, F f) {
    for (size_t i = idx_l; i < idx_r; ++i) {
      m_data[i] = MappingFunc(f, m_data[i]);
    }
  }

  S query(size_t idx_l, size_t idx_r) const {
    assert(idx_l < idx_r);
    S ans{SIdentity};
    for (size_t i = idx_l; i < idx_r; ++i) {
      ans = OpFunc(m_data[i], ans);
    }
    return ans;
  }

 private:
  std::vector<S> m_data;
};
}  // namespace util