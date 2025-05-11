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
  s64 r, x;
  cin >> r >> x;
  const auto get = [&]() -> bool {
    if (x == 1) {
      return 1600 <= r && r <= 2999;
    } else {
      return 1200 <= r && r <= 2399;
    }
  };
  cout << (get() ? "Yes" : "No") << endl;
}
