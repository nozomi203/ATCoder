#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
int main() {
  s64 h, w, k;
  cin >> h >> w >> k;
  vector<vector<s64>> c(w, vector<s64>(h));
  for (s64 i{0}; i < h; ++i) {
    string s;
    cin >> s;
    for (s64 j{0}; j < w; ++j) {
      c[j][h - 1 - i] = s[j] - '0';
    }
  }

  s64 score_max{0};
  for (s64 i{0}; i < h; ++i) {
    for (s64 j{0}; j < w; ++j) {
      s64 score{0};
      vector<vector<s64>> cc(c);
      cc[j].erase(next(cc[j].begin(), i));
      s64 coef{1};
      while (true) {
        vector<vector<bool>> r(w, vector<bool>(h));
        for (s64 x{0}; x < h; ++x) {
          s64 prv{-1};
          s64 seq{0};
          for (s64 y{0}; y < w; ++y) {
            if (x >= cc[y].size()) {
              if (seq >= k) {
                for (s64 l{seq}; l >= 1; --l) {
                  r[y - l][x] = true;
                }
              }
              seq = 0;
              prv = -1;
            } else if (cc[y][x] != prv) {
              if (seq >= k) {
                for (s64 l{seq}; l >= 1; --l) {
                  r[y - l][x] = true;
                }
              }
              seq = 1;
              prv = cc[y][x];
            } else {
              ++seq;
            }

            if (y == w - 1) {
              if (seq >= k) {
                for (s64 l{seq}; l >= 1; --l) {
                  r[y - l + 1][x] = true;
                }
              }
            }
          }
        }

        s64 cnt{0};
        for (s64 x{0}; x < w; ++x) {
          for (s64 y{h - 1}; y >= 0; --y) {
            if (r[x][y]) {
              cnt += cc[x][y];
              cc[x].erase(next(cc[x].begin(), y));
            }
          }
        }

        score += coef * cnt;
        coef *= 2;
        if (!cnt) break;
      }
      score_max = max(score_max, score);
    }
  }

  cout << score_max << endl;
}