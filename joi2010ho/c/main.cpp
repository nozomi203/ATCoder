#include "util/common.h"

int main() {
  size_t n, l;
  cin >> n >> l;
  vector<size_t> as(n + 2);
  util::cin(next(as.begin()), prev(as.end()));
  queue<size_t> q;
  for (size_t i = 1; i <= n; ++i) {
    if (as[i] > as[i - 1] && as[i] > as[i + 1]) {
      q.push(i);
    }
  }

  size_t ans{0};
  vector<size_t> times(n + 2);
  while (!q.empty()) {
    size_t i = q.front();
    q.pop();
    times[i] += l - as[i];
    as[i] = 0;
    ans = max(ans, times[i]);
    if (as[i - 1]) {
      if (as[i - 1] > as[i - 2]) {
        times[i - 1] += times[i];
        q.push(i - 1);
      }
    }
    if (as[i + 1]) {
      if (as[i + 1] > as[i + 2]) {
        times[i + 1] += times[i];
        q.push(i + 1);
      }
    }
  }
  cout << ans << endl;
}