#include "util/common.h"

int main() {
  s64 n;
  struct tf {
    s64 x;
    s64 y;
    s64 z;
    s64 hx_min{numeric_limits<s64>::max()};
    s64 hx_max{numeric_limits<s64>::min()};
    s64 hy_min{numeric_limits<s64>::max()};
    s64 hy_max{numeric_limits<s64>::min()};
    s64 hz_min{numeric_limits<s64>::max()};
    s64 hz_max{numeric_limits<s64>::min()};
  };
  cin >> n;
  vector<tf> tfs(n);
  for (s64 i{0}; i < n; ++i) {
    cin >> tfs[i].x >> tfs[i].y >> tfs[i].z;
    s64 m;
    cin >> m;
    for (s64 j{0}; j < m; ++j) {
      s64 x, y, z;
      cin >> x >> y >> z;
      tfs[i].hx_max = max(tfs[i].hx_max, x);
      tfs[i].hx_min = min(tfs[i].hx_min, x);
      tfs[i].hy_max = max(tfs[i].hy_max, y);
      tfs[i].hy_min = min(tfs[i].hy_min, y);
      tfs[i].hz_max = max(tfs[i].hz_max, z);
      tfs[i].hz_min = min(tfs[i].hz_min, z);
    }
  }

  u64 grundy{0};
  for (const auto& tf : tfs) {
    grundy ^= tf.x - tf.hx_max;
    grundy ^= tf.hx_min;
    grundy ^= tf.y - tf.hy_max;
    grundy ^= tf.hy_min;
    grundy ^= tf.z - tf.hz_max;
    grundy ^= tf.hz_min;
  }
  if (grundy == 0) {
    cout << "LOSE" << endl;
  } else {
    cout << "WIN" << endl;
  }
}