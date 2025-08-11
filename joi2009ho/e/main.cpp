#include "util/common.h"

/*
認証レベルの和lで二分探索
lが与えられたとき、部屋をr以上訪れることができるかが高速に分かればいい


*/

int main() {
  s64 r;
  cin >> r;
  s64 w0, h0, y0, x0;
  cin >> w0 >> h0 >> y0 >> x0;
  vector<vector<s64>> l0ss(h0, vector<s64>(w0));
  util::cin(l0ss);
  s64 w1, h1, y1, x1;
  cin >> w1 >> h1 >> y1 >> x1;
  vector<vector<s64>> l1ss(h1, vector<s64>(w1));
  util::cin(l1ss);

  --x0;
  --y0;
  --x1;
  --y1;

  const auto calc = [&](const vector<vector<s64>>& lss, s64 sx,
                        s64 sy) -> vector<pair<s64, s64>> {
    vector<pair<s64, s64>> ret;
    ret.push_back(make_pair(0, 0));
    const s64 h = lss.size();
    const s64 w = lss[0].size();
    vector<vector<bool>> visited(h, vector<bool>(w));
    using elem_t = tuple<s64, s64, s64>;
    priority_queue<elem_t, vector<elem_t>, greater<elem_t>> pq;
    pq.push(make_tuple(1, sx, sy));

    const auto expand = [&](s64 x, s64 y) {
      visited[x][y] = true;
      const pair<s64, s64> dxys[] = {
          make_pair(0, 1),
          make_pair(0, -1),
          make_pair(1, 0),
          make_pair(-1, 0),
      };
      for (auto [dx, dy] : dxys) {
        auto nx = x + dx;
        auto ny = y + dy;
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (visited[nx][ny]) continue;
        pq.push(make_tuple(lss[nx][ny], nx, ny));
      }
    };

    while (!pq.empty()) {
      auto [l, x, y] = pq.top();
      pq.pop();
      if (visited[x][y]) continue;
      if (ret.back().first < l) {
        ret.push_back(make_pair(l, ret.back().second));
      }

      ++ret.back().second;
      expand(x, y);
    }

    return ret;
  };

  vector<pair<s64, s64>> lc0s(calc(l0ss, x0, y0)), lc1s(calc(l1ss, x1, y1));

  const auto check = [&](s64 l) -> bool {
    for (auto [l0, c0] : lc0s) {
      if (l0 > l) break;
      if (c0 > r) return true;

      auto lrem = l - l0;
      auto crem = r - c0;

      auto it = lower_bound(
          lc1s.begin(), lc1s.end(), crem,
          [](const pair<s64, s64>& e, s64 val) { return e.second < val; });
      if (it == lc1s.end()) {
        continue;
      } else {
        auto [l1, c1] = *it;
        if (l1 <= lrem) return true;
      }
    }

    return false;
  };

  const auto get = [&]() -> s64 {
    s64 ll = 0, lr = 200000000;
    while (lr - ll > 1) {
      s64 l = (ll + lr) / 2;
      if (check(l)) {
        lr = l;
      } else {
        ll = l;
      }
    }
    return lr;
  };

  cout << get() << endl;
}