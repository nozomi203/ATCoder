#line 1 "main.cpp"

#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

template <typename Tuple, std::size_t... I>
void cin_tuple_impl(Tuple& t, std::index_sequence<I...>) {
  ((std::cin >> std::get<I>(t)), ...);
}

template <typename... Ts>
void cin_tuple(tuple<Ts...>& t) {
  cin_tuple_impl(t, index_sequence_for<Ts...>{});
}
#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\sparse_table.h"
#include <bit>
#line 4 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\sparse_table.h"
#include <span>
#include <type_traits>
#line 7 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\sparse_table.h"

namespace util {
template <class TValue, auto OpFunc>
class sparse_table {
  static_assert(std::is_convertible_v<decltype(OpFunc),
                                      std::function<TValue(TValue, TValue)>>);

 public:
  sparse_table(const std::vector<TValue>& data)
      : m_table(std::bit_width(data.size()), std::vector<TValue>(data.size())) {
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
  TValue query(size_t idx_l, size_t idx_r) const {
    assert(idx_l <= idx_r);
    assert(0 <= idx_l);
    assert(idx_r < m_table[0].size());
    const size_t w = std::bit_width(idx_r - idx_l + 1) - 1;
    return OpFunc(m_table[w][idx_l], m_table[w][idx_r - (1 << w) + 1]);
  }

 private:
  std::vector<std::vector<TValue>> m_table;
};
}  // namespace util
#line 4 "main.cpp"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> abs(m);
  for (s64 i{0}; i < m; ++i) cin >> abs[i].first >> abs[i].second;
  s64 q;
  cin >> q;
  vector<pair<s64, s64>> cds(q);
  for (s64 i{0}; i < q; ++i) cin >> cds[i].first >> cds[i].second;

  vector<s64> imos(2 * n + 1);
  for (auto [a, b] : abs) {
    ++imos[a];
    --imos[b];
  }
  for (s64 i{0}; i < 2 * n; ++i) {
    imos[i + 1] += imos[i];
  }
  util::sparse_table<s64, [](s64 v0, s64 v1) { return min(v0, v1); }> st(imos);
  for (auto [c, d] : cds) {
    const s64 v0{st.query(c, c)};
    const s64 v1{st.query(d, d)};
    const s64 vmin{st.query(c, d)};
    cout << v0 + v1 - 2 * vmin << endl;
  }
}
