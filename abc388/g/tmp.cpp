#line 2 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\binary_search.h"
#include <cmath>
#include <concepts>
#include <functional>

namespace util {

template <std::integral Int>
inline std::pair<Int, Int> binary_search(Int ok, Int ng,
                                         std::function<bool(Int value)> check) {
  while (std::abs(ok - ng) > 1) {
    auto mid = (ok + ng) / 2;
    check(mid) ? ok = mid : ng = mid;
  }
  return {ok, ng};
}
}  // namespace util
#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\segment_tree.h"

#line 9 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\segment_tree.h"

#line 2 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\bit.h"

#line 5 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\bit.h"
#include <type_traits>

namespace util {

/// @brief get the most significant bit of 64bit integer v
template <std::unsigned_integral Int>
constexpr uint64_t msb(uint64_t v) {
  for (Int shift = 1; shift < sizeof(Int); shift <<= 1) v |= (v >> shift);
  return v ^ (v >> 1);
}

/// @brief get the smallest power of two equal to greater than the non-negative
/// integer v;
template <std::unsigned_integral Int>
constexpr Int bit_ceil(Int v) {
  if (v == 0) return 1;
  --v;
  for (Int shift = 1; shift < sizeof(Int); shift <<= 1) v |= (v >> shift);
  return v + 1;
}

template <std::unsigned_integral Int>
constexpr Int bit_reverse(Int v) {
  assert(false);
  return {};
}

template <>
constexpr uint32_t bit_reverse(uint32_t v) {
  v = (v & 0x55555555) << 1 | (v >> 1 & 0x55555555);
  v = (v & 0x33333333) << 1 | (v >> 1 & 0x33333333);
  v = (v & 0x0f0f0f0f) << 1 | (v >> 1 & 0x0f0f0f0f);
  v = (v & 0x00ff00ff) << 1 | (v >> 1 & 0x00ff00ff);
  v = (v & 0x0000ffff) << 1 | (v >> 1 & 0x0000ffff);
  return v;
}

template <>
constexpr uint64_t bit_reverse(uint64_t v) {
  v = (v & 0x5555555555555555) << 1 | (v >> 1 & 0x5555555555555555);
  v = (v & 0x3333333333333333) << 1 | (v >> 1 & 0x3333333333333333);
  v = (v & 0x0f0f0f0f0f0f0f0f) << 1 | (v >> 1 & 0x0f0f0f0f0f0f0f0f);
  v = (v & 0x00ff00ff00ff00ff) << 1 | (v >> 1 & 0x00ff00ff00ff00ff);
  v = (v & 0x0000ffff0000ffff) << 1 | (v >> 1 & 0x0000ffff0000ffff);
  v = (v & 0x00000000ffffffff) << 1 | (v >> 1 & 0x00000000ffffffff);
  return v;
}

}  // namespace util
#line 11 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\segment_tree.h"

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
#line 4 "main.cpp"

int main() {
  s64 N;
  cin >> N;
  vector<s64> A(N);
  for (s64 i = 0; i < N; ++i) cin >> A[i];

  vector<s64> diffs(N);
  for (s64 i{0}, j{0}; i < N; ++i) {
    while (j < N && A[i] * 2 > A[j]) ++j;
    diffs[i] = j - i;
  }

  using S = s64;
  constexpr S kSIdentity = 0;
  constexpr auto kOpFunc = [](S l, S r) -> S { return max(l, r); };
  util::segment_tree<S, kSIdentity, kOpFunc> st(diffs);

  s64 Q;
  cin >> Q;
  vector<pair<s64, s64>> lr(Q);
  for (s64 i = 0; i < Q; ++i) {
    cin >> lr[i].first >> lr[i].second;
    --lr[i].first;
  }

  vector<s64> answers;
  for (s64 i = 0; i < Q; ++i) {
    auto [l, r] = lr[i];
    // 鏡餅の数の最大を探索
    auto [ok, ng] = util::binary_search<s64>(0, r - l, [&](s64 value) -> bool {
      auto q = st.query(l, l + value);
      return l + value - 1 + max(q, value) < r;
    });
    answers.push_back(ok);
  }

  for (auto answer : answers) {
    cout << answer << endl;
  }
}
