#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\lazy_segment_tree.h"
#include <bit>
#line 3 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\lazy_segment_tree.h"
#include <concepts>
#line 7 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\lazy_segment_tree.h"
#include <optional>
#line 10 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\lazy_segment_tree.h"

#line 2 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\bit.h"

#line 5 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\bit.h"
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
#line 2 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\concepts.h"

namespace util::concepts {

template <class T, class TRet, class... TArgs>
concept Function = requires(T func, TArgs... args) {
  { func(args...) } -> std::convertible_to<TRet>;
};

}  // namespace util
#line 13 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\lazy_segment_tree.h"

namespace util {
template <class S, class F, S SIdentity, auto OpFunc, auto MappingFunc,
          auto CompositionFunc>
class lazy_segment_tree {
  static_assert(
      std::is_convertible_v<decltype(OpFunc), std::function<S(S, S)>>);
  static_assert(
      std::is_convertible_v<decltype(MappingFunc), std::function<S(F, S)>>);
  static_assert(
      std::is_convertible_v<decltype(CompositionFunc), std::function<F(F, F)>>);

 public:
  lazy_segment_tree(size_t n) : lazy_segment_tree(std::vector(n, SIdentity)) {}
  lazy_segment_tree(size_t n, S&& value)
      : lazy_segment_tree(std::vector(n, value)) {}
  lazy_segment_tree(size_t n, const S& value)
      : lazy_segment_tree(std::vector(n, value)) {}
  lazy_segment_tree(const std::vector<S>& values)
      : m_n(values.size()),
        m_depth_max(std::countr_zero(bit_ceil(values.size()))),
        m_data((bit_ceil(values.size()) << 1)),
        m_lazy(bit_ceil(values.size()), std::nullopt) {
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
    if (m_lazy[data_idx]) {
      apply(data_idx * 2 + 0, *m_lazy[data_idx]);
      apply(data_idx * 2 + 1, *m_lazy[data_idx]);
      m_lazy[data_idx] = std::nullopt;
    }
  }
  void apply(size_t data_idx, F f) {
    m_data[data_idx] = MappingFunc(f, m_data[data_idx]);
    if (data_idx < m_n) {
      m_lazy[data_idx] =
          m_lazy[data_idx] ? CompositionFunc(f, *m_lazy[data_idx]) : f;
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
  std::vector<std::optional<F>> m_lazy;
};
}  // namespace util
#line 3 "main.cpp"

int main() {
  s64 N;
  cin >> N;
  vector<s64> A(N);
  for (s64 i = 0; i < N; ++i) {
    cin >> A[i];
  }

  using S = s64;
  using F = s64;
  constexpr S kSIdentity = numeric_limits<s64>::min();
  constexpr auto kOpFunc = [](S a, S b) -> S { return max(a, b); };
  constexpr auto kMappingFunc = [](F f, S s) -> S { return s + f; };
  constexpr auto kCompositionFunc = [](F f0, F f1) -> F { return f0 + f1; };
  util::lazy_segment_tree<S, F, kSIdentity, kOpFunc, kMappingFunc,
                          kCompositionFunc>
      lst(A);

  for (s64 i = 0; i < N - 1; ++i) {
    const s64 stone_count = lst.query(i, i + 1);
    const s64 drop_count = min(stone_count, N - i - 1);
    const s64 idx_r = i + drop_count + 1;
    if (drop_count > 0) {
      lst.apply(i, i + 1, -drop_count);
      lst.apply(i + 1, idx_r, 1);
    }
  }

  for (s64 i = 0; i < N; ++i) {
    const auto q = lst.query(i, i + 1);
    cout << q;
    if (i < N - 1) cout << " ";
  }
  cout << endl;
}
