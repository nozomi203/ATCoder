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

template <typename... Ts, size_t N>
void cin_tuple(tuple<Ts...>& t) {
  static_assert(N <= sizeof...(Ts));
  cin_tuple_impl(t, index_sequence_for<N>{});
}

template <typename First, typename Second>
void cin_pair(pair<First, Second>& p) {
  cin >> p.first >> p.second;
}