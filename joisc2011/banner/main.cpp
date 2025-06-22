#include "util/common.h"

size_t get_idx(size_t x, size_t y) {
  if (x > y) swap(x, y);
  switch (x) {
    case 0:
      switch (y) {
        case 0:
          return 0;
        case 1:
          return 1;
        case 2:
          return 2;
      }
    case 1:
      switch (y) {
        case 1:
          return 3;
        case 2:
          return 4;
      }
    case 2:
      switch (y) {
        case 2:
          return 5;
      }
  }
}

int main() {
  size_t h, w;
  cin >> h >> w;
  vector<vector<size_t>> css(h, vector<size_t>(w));
  util::cin(css);

  size_t ans = 0;
  for (size_t i = 0; i < h - 1; ++i) {
    for (size_t j = i + 1; j < h; ++j) {
      // acum[i][j][k] = 0~i列目までで柱の色がj,kになっている列の数
      vector acum(w, array<size_t, 6>{0, 0, 0, 0, 0, 0});
      acum[0][get_idx(css[i][0], css[j][0])] = 1;
      for (size_t k = 1; k < w; ++k) {
        for (size_t l = 0; l < 6; ++l) {
          acum[k][l] = acum[k - 1][l];
        }
        acum[k][get_idx(css[i][k], css[j][k])]++;
      }

      for (size_t k = 0; k < w; ++k) {
        switch (get_idx(css[i][k], css[j][k])) {
          case 0:
            ans += acum[w - 1][4] - acum[k][4];
            break;
          case 1:
            ans += acum[w - 1][2] - acum[k][2];
            ans += acum[w - 1][4] - acum[k][4];
            ans += acum[w - 1][5] - acum[k][5];
            break;
          case 2:
            ans += acum[w - 1][1] - acum[k][1];
            ans += acum[w - 1][3] - acum[k][3];
            ans += acum[w - 1][4] - acum[k][4];
            break;
          case 3:
            ans += acum[w - 1][2] - acum[k][2];
            break;
          case 4:
            ans += acum[w - 1][0] - acum[k][0];
            ans += acum[w - 1][1] - acum[k][1];
            ans += acum[w - 1][2] - acum[k][2];
            break;
          case 5:
            ans += acum[w - 1][1] - acum[k][1];
            break;
        }
      }
    }
  }
  cout << ans << endl;
}