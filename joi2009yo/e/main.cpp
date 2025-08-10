#include "util/common.h"

int main() {
  size_t n;
  size_t m;
  size_t p, q, r;
  cin >> n >> m >> p >> q >> r;
  vector<pair<size_t, size_t>> xys(m);
  util::cin(xys);

  using node = pair<size_t, size_t>;
  vector<node> nodes;
  nodes.push_back(node{1, n});

  for (auto [x, y] : xys) {
    size_t ix = 0;
    size_t iy = 0;
    size_t cnt = nodes[0].second;
    while (cnt < x) cnt += nodes[++ix].second;
    if (cnt > x) {
      nodes.insert(nodes.begin() + ix,
                   make_pair(nodes[ix].first, nodes[ix].second - (cnt - x)));
      nodes[ix + 1].first = nodes[ix].first + nodes[ix].second;
      nodes[ix + 1].second = cnt - x;
      iy = ix + 1;
    } else {
      iy = ix;
    }
    while (cnt < y) cnt += nodes[++iy].second;
    if (cnt > y) {
      nodes.insert(nodes.begin() + iy,
                   make_pair(nodes[iy].first, nodes[iy].second - (cnt - y)));
      nodes[iy + 1].first = nodes[iy].first + nodes[iy].second;
      nodes[iy + 1].second = cnt - y;
    }

    vector<node> tmp;
    tmp.reserve(nodes.size());
    for (size_t i = iy + 1; i < nodes.size(); ++i) tmp.push_back(nodes[i]);
    for (size_t i = ix + 1; i <= iy; ++i) tmp.push_back(nodes[i]);
    for (size_t i = 0; i <= ix; ++i) tmp.push_back(nodes[i]);
    swap(tmp, nodes);
  }

  const auto get = [&]() -> size_t {
    size_t ans = 0;
    size_t sumcnt = 0;
    for (size_t i = 0; i < nodes.size(); ++i) {
      const auto [head, cnt] = nodes[i];
      const size_t p_ = max(sumcnt + 1, p);
      const size_t q_ = min(sumcnt + cnt, q);
      if (p_ <= q_ && r >= head) {
        const size_t r_ = sumcnt + (r - head) + 1;
        if (r_ >= p_) {
          ans += min(r_, q_) - p_ + 1;
        }
      }
      sumcnt += cnt;
    }
    return ans;
  };

  cout << get() << endl;
}