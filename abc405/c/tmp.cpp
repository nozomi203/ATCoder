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
  s64 n;
  cin >> n;
  vector<s64> a(n);
  for (s64 i{0}; i < n; ++i) cin >> a[i];
  vector<s64> suma(n);
  suma[0] = a[0];
  for (s64 i{1}; i < n; ++i) {
    suma[i] = suma[i - 1] + a[i];
  }

  s64 ans{0};
  for (s64 i{0}; i < n - 1; ++i) {
    ans += a[i] * (suma[n - 1] - suma[i]);
  }
  cout << ans << endl;
}
