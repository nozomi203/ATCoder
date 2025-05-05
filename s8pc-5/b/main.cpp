#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

struct circle {
  double x;
  double y;
  double r;
  bool fixed{false};
};

double dist(const circle& c0, const circle& c1) {
  const double dx = c1.x - c0.x;
  const double dy = c1.y - c0.y;
  return sqrt(dx * dx + dy * dy);
}

using namespace std;
int main() {
  s64 n, m;
  cin >> n >> m;
  vector<circle> circles(n + m);

  for (s64 i{0}; i < n; ++i) {
    cin >> circles[i].x >> circles[i].y >> circles[i].r;
    circles[i].fixed = true;
  }
  for (s64 i{0}; i < m; ++i) {
    cin >> circles[n + i].x >> circles[n + i].y;
    circles[n + i].fixed = false;
  }

  s64 num_fixed{0};
  while (num_fixed < m) {
    s64 min_i{0};
    double d_i{numeric_limits<double>::max()};
    for (s64 i{n}; i < n + m; ++i) {
      if (circles[i].fixed) continue;
      s64 min_j{0};
      double d_j{numeric_limits<double>::max()};
      for (s64 j{0}; j < n + m; ++j) {
        if (i == j) continue;
        double d = circles[j].fixed
                       ? dist(circles[i], circles[j]) - circles[j].r
                       : dist(circles[i], circles[j]) * 0.5;
        if (d < d_j) {
          d_j = d;
          min_j = j;
        }
      }
      if (d_j < d_i) {
        min_i = i;
        d_i = d_j;
      }
    }
    circles[min_i].fixed = true;
    circles[min_i].r = d_i;
    ++num_fixed;
  }

  double min_r{numeric_limits<double>::max()};
  for (s64 i{0}; i < n + m; ++i) min_r = min(min_r, circles[i].r);
  cout << fixed << setprecision(15) << min_r << endl;
}