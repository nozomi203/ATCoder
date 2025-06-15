#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>
namespace util {

template <typename IntBefore = int64_t, typename IntAfter = int64_t>
class value_compressor {
 public:
  using value_type_before = IntBefore;
  using value_type_after = IntAfter;

 public:
  value_compressor() = default;
  value_compressor(size_t capacity) { m_values.reserve(capacity); }

 public:
  void add(value_type_before value) {
    assert(!is_compressed());
    m_values.emplace_back(value, -1);
  }
  void compress() {
    std::sort(m_values.begin(), m_values.end());
    m_values.erase(std::unique(m_values.begin(), m_values.end()),
                   m_values.end());
    value_type_after idx{0};
    for (auto& [value, to] : m_values) to = idx++;
  }

  bool is_compressed() const {
    return !m_values.empty() && m_values.front().second >= 0;
  }

  value_type_after value_after_compression(
      value_type_before value_before_compression) const {
    assert(is_compressed());
    auto it = std::lower_bound(
        m_values.begin(), m_values.end(), value_before_compression,
        [](const std::pair<value_type_before, value_type_after>& p,
           value_type_before v) { return p.first < v; });
    if (it == m_values.end()) return -1;
    return it->second;
  }

  value_type_before value_before_compression(
      value_type_after value_after_compression) const {
    assert(is_compressed());
    return m_values[value_after_compression].first;
  }

  size_t size() const {
    assert(is_compressed());
    return m_values.size();
  }

 private:
  std::vector<std::pair<value_type_before, value_type_after>> m_values;
};
};  // namespace util