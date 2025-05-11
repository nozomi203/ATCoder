#line 1 "main.cpp"
#include <atcoder/modint>

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
#line 4 "main.cpp"

using mint = atcoder::modint998244353;

mint fact(s64 n) {
  mint ans = 1;
  for (s64 i{1}; i <= n; ++i) ans *= i;
  return ans;
}

int main() {
  s64 a, b, c, d;
  cin >> a >> b >> c >> d;

  mint x = fact(a + b);
  mint y = fact(a) * fact(b);
  mint z = fact(d - 1 + c);
  mint w = fact(d - 1) * fact(c);

  mint ans = 1;
  ans *= x;
  ans /= y;
  ans *= z;
  ans /= w;
  mint tmp = ans;
  for (s64 i{1}; i <= c; ++i) {
    tmp *= (a + b + i);
    tmp /= (a + i);
    tmp /= (d - 1 + c - i + 1);
    tmp *= (c - i + 1);
    ans += tmp;
  }
  cout << ans.val() << endl;
}
