#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <concepts>
#include <cstdint>
#include <vector>

namespace util {
template <std::unsigned_integral uint_type>
class radix_heap {
 public:
  /// @brief push value to heap. <v> must be equal or less than last popped
  /// value(0 if pop has never been called)
  /// @param v value to push
  void push(uint_type v) {
    assert(v >= m_last);
    ++m_size;
    m_heap[std::bit_width(v ^ m_last)].push_back(v);
  }

  /// @brief get minimum value from heap
  /// @return minimum value
  uint_type pop() {
    if (m_heap[0].empty()) {
      for (size_t i{1}; i < heap_size; ++i) {
        if (m_heap[i].empty()) continue;
        auto it = std::min_element(m_heap[i].cbegin(), m_heap[i].cend());
        const uint_type new_last = *it;
        for (auto v : m_heap[i]) {
          m_heap[std::bit_width(v ^ new_last)].push_back(v);
        }
        m_last = new_last;
        m_heap[i].clear();
        break;
      }
    }
    --m_size;
    m_heap[0].pop_back();
    return m_last;
  }

  size_t size() const noexcept { return m_size; }

 private:
  static constexpr size_t heap_size = sizeof(uint_type) * CHAR_BIT + 1;
  std::array<std::vector<uint_type>, heap_size> m_heap;
  uint_type m_last{0};
  size_t m_size{0};
};

using radix_heap32 = radix_heap<uint32_t>;
using radix_heap64 = radix_heap<uint64_t>;
}  // namespace util