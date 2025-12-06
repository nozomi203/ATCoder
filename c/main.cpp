#include "util/common.h"

/*
dpl[i] = 条件iを満たしつつ到達できる最小の高さ
dph[i] = 条件iを満たしつつ到達できる最大の高さ

dpl[i] =
*/

int main() {
  s64 t;
  cin >> t;
  vector<tuple<s64, s64, vector<tuple<s64, s64, s64>>>> cases(t);
  for (auto& [n, h, tlus] : cases) {
    cin >> n >> h;
    tlus.resize(n);
    util::cin(tlus);
  }

  for (const auto& [n, h, tlhs] : cases) {
    const auto check = [&]() -> bool {
      vector<s64> dpl(n), dph(n);
      {
        auto [t0, low0, high0] = tlhs[0];
        s64 remt = t0;
        if (h - remt > high0 || h + remt < low0) return false;
        dpl[0] = max(h - remt, low0);
        dph[0] = min(h + remt, high0);
      }

      for (s64 i = 1; i < n; ++i) {
        auto [pt, plow, phigh] = tlhs[i - 1];
        auto [t, low, high] = tlhs[i];
        s64 remt = t - pt;
        if (dpl[i - 1] - remt > high || dph[i - 1] + remt < low) return false;
        dpl[i] = max(dpl[i - 1] - remt, low);
        dph[i] = min(dph[i - 1] + remt, high);
      }
      return true;
    };

    cout << (check() ? "Yes" : "No") << endl;
  }
}