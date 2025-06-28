#include "util/common.h"

/*
箱の数iを固定したとき、コストc=k*i+sum(si * (ai - bi))
箱の数がn個の状態から箱をマージすることを考える
となりあった領域i, i+1をマージした時のコストの変化量dc = -k + (s[i] + s[i+1]) *
(max(a[i],a[i+1]) - min(b[i],b[i+1])) - s[i]*(a[i]-b[i]) -
s[i+1]*(a[i+1]-b[i+1])

a[i]>a[i+1] && b[i]>b[i+1]のとき
-k + (s[i]+s[i+1])*(a[i] - b[i+1]) - s[i]*(a[i]-b[i]) - s[i+1]*(a[i+1]-b[i+1])
=-k+s[i]*(b[i]-b[i+1]) + s[i+1](a[i] - a[i+1]);

a[i]>a[i+1] && b[i]<b[i+1]のとき
=-k+s[i+1]*(a[i+1]-b[i+1])

a[i]<a[i+1] && b[i]>b[i+1])のとき
=-k


この変化量が最も小さいところをマージする.priority_queueで管理できそう。すでにマージされたところはスキップ
*/

int main() {
  int64_t n, m, k;
  cin >> n >> m >> k;
  vector<int64_t> as(n);
  util::cin(as);

  vector<int64_t> next(n);
  iota(next.begin(), next.end(), 0);

  struct box {
    int64_t cnt;
    int64_t amin;
    int64_t amax;
  };
  map<int64_t, box> bmap;
  for (int64_t i = 0; i < n; ++i) {
    bmap.emplace(i, box{1, as[i], as[i]});
  }

  const auto get_merge_cost = [&](const box& b0, const box& b1) -> int64_t {
    return -k +
           (b0.cnt + b1.cnt) * (max(b0.amax, b1.amax) - min(b0.amin, b1.amin)) -
           b0.cnt * (b0.amax - b0.amin) - b1.cnt * (b1.amax - b1.amin);
  };

  using work = tuple<int64_t, int64_t, int64_t, int64_t>;
  priority_queue<work, vector<work>, greater<work>> pq;
  for (size_t i = 0; i < n - 1; ++i) {
    const int64_t c = get_merge_cost(bmap[i], bmap[i + 1]);
    pq.push(make_tuple(c, i, i + 1, 2));
  }

  int64_t cost = k * n;
  int64_t cost_min = cost;
  while (!pq.empty()) {
    auto [c, i0, i1, cnt] = pq.top();
    pq.pop();

    auto it0 = bmap.find(i0);
    auto it1 = bmap.find(i1);
    if (it0 == bmap.end() || it1 == bmap.end())
      continue;  // situation has changed since it was emplaced to pq

    if (it0->second.cnt + it1->second.cnt != cnt) continue;
    if (it0->second.cnt + it1->second.cnt > m) continue;
    it0->second.cnt += it1->second.cnt;
    it0->second.amax = max(it0->second.amax, it1->second.amax);
    it0->second.amin = min(it0->second.amin, it1->second.amin);
    cost += c;
    cost_min = min(cost_min, cost);

    bmap.erase(it1);
    it0 = bmap.find(i0);
    if (std::next(it0) != bmap.end()) {
      const auto& [idx0, b0] = *it0;
      const auto& [idx1, b1] = *std::next(it0);
      const int64_t c = get_merge_cost(b0, b1);
      const int64_t cnt = b0.cnt + b1.cnt;
      pq.push(make_tuple(c, idx0, idx1, cnt));
    }
    if (it0 != bmap.begin()) {
      const auto& [idx0, b0] = *std::prev(it0);
      const auto& [idx1, b1] = *it0;
      const int64_t c = get_merge_cost(b0, b1);
      const int64_t cnt = b0.cnt + b1.cnt;
      pq.push(make_tuple(c, idx0, idx1, cnt));
    }
  }

  cout << cost_min << endl;
}