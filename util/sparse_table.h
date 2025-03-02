#include <bit>
#include <span>
#include <type_traits>
#include <vector>

namespace util {
template <class TValue, TValue OpIdentity, class TResult, auto OpFunc>
class sparse_table {
  static_assert(std::is_convertible_v<
                decltype(OpFunc), std::function<TResult(TResult, TResult)>>);

 public:
  sparse_table(const std::vector<TValue>& data)
      : m_table(std::bit_width(data.size()) - 1,
                std::vector<TResult>(data.size())) {
    for (size_t j{0}; j < data.size(); ++j) m_table[0][j] = data[j];
    for (size_t i{0}; i < m_table.size(); ++i) {
      for (size_t j{1}; j < data.size(); ++j) {
        m_table[i][j] =
            OpFunc(m_table[i - 1][j], m_table[i - 1][j + (1 << (i - 1))])
      }
    }
  }

 public:
  TResult query(size_t idx_l, size_t idx_r) {}

 private:
  std::vector<std::vector<TResult>> m_table;
};
}  // namespace util