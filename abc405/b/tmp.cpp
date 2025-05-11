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
#line 2 "main.cpp"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];

  const auto get = [&]() -> s64 {
    map<s64, s64> mp;
    for (s64 i{0}; i < n; ++i) {
      if (a[i] <= m) {
        ++mp[a[i]];
      }
    }

    if (mp.size() < m) return 0;

    for (s64 i{n - 1}; i >= 0; --i) {
      if (a[i] <= m) {
        if (--mp[a[i]] == 0) return n - i;
      }
    }
  };

  cout << get() << endl;
}
