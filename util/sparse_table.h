#include <bit>
#include <cassert>
#include <functional>
#include <span>
#include <type_traits>
#include <vector>

namespace util {
template <class TValue, class TResult, auto OpFunc>
class sparse_table {
  static_assert(std::is_convertible_v<
                decltype(OpFunc), std::function<TResult(TResult, TResult)>>);

 public:
  sparse_table(const std::vector<TValue>& data)
      : m_table(std::bit_width(data.size()),
                std::vector<TResult>(data.size())) {
    assert(data.size() > 0);
    for (size_t j{0}; j < data.size(); ++j) m_table[0][j] = data[j];
    for (size_t i{1}; i < m_table.size(); ++i) {
      for (size_t j{0}; j < data.size(); ++j) {
        if (j + (1 << (i - 1)) >= data.size()) continue;
        m_table[i][j] =
            OpFunc(m_table[i - 1][j], m_table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

 public:
  /// @brief get op result of range [idx_l, idx_r]
  /// @param idx_l
  /// @param idx_r
  /// @return
  TResult query(size_t idx_l, size_t idx_r) {
    assert(idx_l <= idx_r);
    assert(0 <= idx_l);
    assert(idx_r < m_table[0].size());
    const size_t w = std::bit_width(idx_r - idx_l + 1) - 1;
    return OpFunc(m_table[w][idx_l], m_table[w][idx_r - (1 << w) + 1]);
  }

 private:
  std::vector<std::vector<TResult>> m_table;
};
}  // namespace util