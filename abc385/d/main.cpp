#include "util/common.h"

int main() {
  s64 n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  map<s64, set<s64>> house_x, house_y;
  for (s64 i = 0; i < n; ++i) {
    s64 x, y;
    cin >> x >> y;
    house_x[y].insert(x);
    house_y[x].insert(y);
  }
  s64 ans{0};
  for (s64 i = 0; i < m; ++i) {
    char d;
    s64 c;
    cin >> d >> c;
    if (d == 'U') {
      auto it = house_y[sx].lower_bound(sy);
      while (it != house_y[sx].end() && *it <= sy + c) {
        ++ans;
        house_x[*it].erase(sx);
        it = house_y[sx].erase(it);
      }
      sy += c;
    } else if (d == 'D') {
      auto it = house_y[sx].lower_bound(sy - c);
      while (it != house_y[sx].end() && *it <= sy) {
        ++ans;
        house_x[*it].erase(sx);
        it = house_y[sx].erase(it);
      }
      sy -= c;
    } else if (d == 'L') {
      auto it = house_x[sy].lower_bound(sx - c);
      while (it != house_x[sy].end() && *it <= sx) {
        ++ans;
        house_y[*it].erase(sy);
        it = house_x[sy].erase(it);
      }
      sx -= c;
    } else {
      auto it = house_x[sy].lower_bound(sx);
      while (it != house_x[sy].end() && *it <= sx + c) {
        ++ans;
        house_y[*it].erase(sy);
        it = house_x[sy].erase(it);
      }
      sx += c;
    }
  }

  cout << sx << " " << sy << " " << ans << endl;
}