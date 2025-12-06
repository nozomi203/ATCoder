#include "util/common.h"

int main() {
  s64 n, k;
  cin >> n >> k;
  vector<tuple<s64, s64, s64>> abcs(n);
  util::cin(abcs);

  s64 sum = 0;
  s64 time = 0;
  using elem_t = pair<s64, s64>; /*退店時間, 人数*/
  priority_queue<elem_t, vector<elem_t>, greater<elem_t>> pq;

  for (auto [a, b, c] : abcs) {
    if (time < a) time = a;
    while (sum + c > k) {
      const auto [x, y] = pq.top();
      time = max(time, x);
      sum -= y;
      pq.pop();
    }
    pq.push(make_pair(time + b, c));
    sum += c;
    cout << time << endl;
  }
}