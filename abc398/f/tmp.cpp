#line 2 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\binary_search.h"
#include <cmath>
#include <concepts>
#include <functional>

namespace util {

template <std::signed_integral Int>
inline std::pair<Int, Int> binary_search(Int ok, Int ng,
                                         std::function<bool(Int value)> check) {
  while (std::abs(ok - ng) > 1) {
    auto mid = (ok + ng) / 2;
    check(mid) ? ok = mid : ng = mid;
  }
  return {ok, ng};
}
}  // namespace util
#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 3 "main.cpp"

int main() {
  string s;
  cin >> s;

  const auto check_odd = [](const string& s, s64 c) -> bool {
    assert(c >= s.size() / 2);
    s64 diff{1};
    while (true) {
      const auto idx_l{c - diff}, idx_r{c + diff};
      if (idx_r >= s.size()) return true;
      if (s[idx_l] != s[idx_r]) return false;
      ++diff;
    }
  };
  const auto check_even = [](const string& s, s64 c) -> bool {
    assert(c >= (s.size() - 1) / 2);
    s64 diff{0};
    while (true) {
      const auto idx_l{c - diff}, idx_r{c + 1 + diff};
      if (idx_r >= s.size()) return true;
      if (s[idx_l] != s[idx_r]) return false;
      ++diff;
    }
  };

  const auto get_idx_odd = [&]() -> s64 {
    if (s.size() < 3) return s.size() - 1;
    if (check_odd(s, s.size() / 2)) return s.size() / 2;
    auto [c_ok, c_ng] = util::binary_search<s64>(
        s.size() - 1, s.size() / 2,
        [&](s64 v) -> bool { return check_odd(s, v); });
    return c_ok;
  };
  const auto get_idx_even = [&]() -> s64 {
    if (s.size() < 2) return s.size() - 1;
    if (check_even(s, (s.size() - 1) / 2)) return (s.size() - 1) / 2;
    auto [c_ok, c_ng] = util::binary_search<s64>(
        s.size() - 1, (s.size() - 1) / 2,
        [&](s64 v) -> bool { return check_even(s, v); });
    return c_ok;
  };

  auto odd_idx = get_idx_odd();
  auto even_idx = get_idx_even();
  if (odd_idx * 2 + 1 <= (even_idx + 1) * 2) {
    for (s64 i{0}; i < odd_idx; ++i) cout << s[i];
    cout << s[odd_idx];
    for (s64 i{odd_idx - 1}; i >= 0; --i) cout << s[i];
    cout << endl;
  } else {
    for (s64 i{0}; i <= even_idx; ++i) cout << s[i];
    for (s64 i{even_idx}; i >= 0; --i) cout << s[i];
    cout << endl;
  }
}
