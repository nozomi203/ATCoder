#pragma once
#include <algorithm>
#include <cstdint>
#include <vector>

namespace util {
namespace arg_sort {
template <typename value_type>
using vec2_type = std::pair<value_type, value_type>;

/// @brief vの各要素を2次元ベクトルとみなして偏角ソートする
/// @param v
template <typename value_type>
inline void sort(std::vector<vec2_type<value_type>>& v) {
  using elem_type = vec2_type<value_type>;
  auto it = std::partition(v.begin(), v.end(),
                           [&](const elem_type& e) { return elem_type{} < e; });
  const auto cmp = [&](const elem_type& e0, const elem_type& e1) {
    return e0.first * e1.second > e0.second * e1.first;
  };
  std::sort(v.begin(), it, cmp);
  std::sort(it, v.end(), cmp);
}
}  // namespace arg_sort

}  // namespace util