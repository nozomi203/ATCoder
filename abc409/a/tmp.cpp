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

template <typename First, typename Second>
void cin_pair(pair<First, Second>& p) {
  cin >> p.first >> p.second;
}
#line 2 "main.cpp"

int main() {
  size_t n;
  cin >> n;
  string t, a;
  cin >> t >> a;
  const auto check = [&]() -> bool {
    for (size_t i{0}; i < n; ++i)
      if (t[i] == 'o' && a[i] == 'o') return true;
    return false;
  };
  cout << (check() ? "Yes" : "No") << endl;
}
