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

u64 get_digit(u64 v) {
  u64 ret{0};
  while (v) {
    v /= 10;
    ++ret;
  }
  return ret;
}
u64 mul(u64 a, u64 b, u64 k) {
  u64 ret{0};
  u64 digit{0};
  u64 ten{1};
  while (b) {
    u64 v = b % 10;
    b /= 10;
    u64 w = a * v;
    if (get_digit(w) >= k + 1 - digit) return 1;
    w *= ten;
    ret += w;
    if (get_digit(ret) >= k + 1) return 1;
    ten *= 10;
    ++digit;
  }
  return ret;
}

int main() {
  u64 n, k;
  cin >> n >> k;
  vector<u64> as(n);
  for (u64 i{0}; i < n; ++i) cin >> as[i];

  u64 v{1};
  for (auto a : as) {
    v = mul(v, a, k);
  }
  cout << v << endl;
}
