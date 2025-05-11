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
  s64 h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (s64 i{0}; i < h; ++i) {
    cin >> s[i];
  }
  using pos = pair<s64, s64>;
  vector<vector<pos>> d(
      h, vector<pos>(w, make_pair(numeric_limits<s64>::max(), -1)));

  const tuple<s64, s64, char> dxys[] = {
      make_tuple(-1, 0, 'v'),
      make_tuple(1, 0, '^'),
      make_tuple(0, -1, '>'),
      make_tuple(0, 1, '<'),
  };

  const auto check = [&](s64 x, s64 y) -> bool {
    if (x < 0 || x >= h || y < 0 || y >= w) return false;
    if (s[x][y] != '.') return false;
    return true;
  };

  queue<pos> q;
  for (s64 i{0}; i < h; ++i) {
    for (s64 j{0}; j < w; ++j) {
      if (s[i][j] == 'E') {
        for (auto [dx, dy, c] : dxys) {
          const auto nx{i + dx}, ny{j + dy};
          if (!check(nx, ny)) continue;
          s[nx][ny] = c;
          q.push(make_pair(nx, ny));
        }
      }
    }
  }
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (auto [dx, dy, c] : dxys) {
      const auto nx{x + dx}, ny{y + dy};
      if (!check(nx, ny)) continue;
      s[nx][ny] = c;
      q.push(make_pair(nx, ny));
    }
  }

  for (s64 i{0}; i < h; ++i) {
    for (s64 j{0}; j < w; ++j) {
      cout << s[i][j];
    }
    cout << endl;
  }
}
