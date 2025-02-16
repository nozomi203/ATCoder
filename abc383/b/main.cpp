#include "util/common.h"

int main() {
  s64 H, W, D;
  cin >> H >> W >> D;
  vector<string> office(H);
  for (s64 i = 0; i < H; ++i) cin >> office[i];

  s64 ans{0};
  for (s64 i = 0; i < H; ++i) {
    for (s64 j = 0; j < W; ++j) {
      for (s64 k = 0; k < H; ++k) {
        for (s64 l = 0; l < W; ++l) {
          if (office[i][j] != '.' || office[k][l] != '.') continue;
          s64 cnt{0};
          for (s64 m = 0; m < H; ++m) {
            for (s64 n = 0; n < W; ++n) {
              if (office[m][n] != '.') continue;
              if (abs(i - m) + abs(j - n) <= D || abs(k - m) + abs(l - n) <= D)
                ++cnt;
            }
          }
          ans = max(ans, cnt);
        }
      }
    }
  }

  cout << ans << endl;
}