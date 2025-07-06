#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

namespace util {

template <typename T>
inline void cin(T& t) {
  std::cin >> t;
}

template <typename Tuple, std::size_t... I>
inline void cin_tuple_impl(Tuple& t, std::index_sequence<I...>) {
  ((util::cin(std::get<I>(t))), ...);
}

template <typename... Ts>
inline void cin(tuple<Ts...>& t) {
  cin_tuple_impl(t, index_sequence_for<Ts...>{});
}

template <typename First, typename Second>
inline void cin(pair<First, Second>& p) {
  util::cin(p.first);
  util::cin(p.second);
}

template <typename T>
inline void cin(vector<T>& v) {
  for (auto& e : v) {
    util::cin(e);
  }
}

template <typename Iterator>
inline void cin(Iterator first, Iterator last) {
  for (auto it = first; it != last; ++it) {
    util::cin(*it);
  }
}

template <typename T>
inline void sort(vector<T>& v) {
  std::sort(v.begin(), v.end());
}

template <typename T, typename Compare>
inline void sort(vector<T>& v, Compare comp) {
  std::sort(v.begin(), v.end(), std::forward(comp));
}

}  // namespace util