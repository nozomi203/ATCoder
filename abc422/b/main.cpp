#include "util/common.h"

int main() {
  s64 h, w;
  cin >> h >> w;
  vector<string> ss(h);
  util::cin(ss);

  const auto check = [&]() -> bool {
    for (s64 i = 0; i < h; ++i) {
      for (s64 j = 0; j < w; ++j) {
        if (ss[i][j] != '#') continue;
        s64 cnt = 0;
        if (i > 0 && ss[i - 1][j] == '#') ++cnt;
        if (i < h - 1 && ss[i + 1][j] == '#') ++cnt;
        if (j > 0 && ss[i][j - 1] == '#') ++cnt;
        if (j < w - 1 && ss[i][j + 1] == '#') ++cnt;

        if (cnt != 2 && cnt != 4) return false;
      }
    }

    return true;
  };

  cout << (check() ? "Yes" : "No") << endl;
}