#include "util/common.h"

/*
2x2の黒マスの塊をブロックと呼ぶ。
ブロックの左上のマスの座標が(i,j)であるブロックをブロック(i,j)とよぶ。
あるブロック(i,j)について、マスを共有するほかのブロックの数をN(i,j)とする。
0 <= N(i,j) <= 8
まず、N(i,j) = 0であるブロックについて左上のマスを白にする。
次に、N(i,j) =
1であるブロックについて共有されているブロックのいずれかを白にする。
ここまでで、隣接ブロック数2以上のブロックだけが残る。
ブロックがなくなるまで、0<=N<=3のブロックに対処し続ければOK
*/

int main() {
  u32 t;
  cin >> t;
  vector<tuple<u32, u32, vector<string>>> cases(t);
  for (auto& [h, w, ss] : cases) {
    cin >> h >> w;
    ss.resize(h);
    util::cin(ss);
  }

#if 0
  for (auto& [h, w, ss] : cases) {
    const auto check_block = [&](u32 i, u32 j) -> bool {
      if (i < 0 || i >= h - 1 || j < 0 || j >= w - 1) return false;
      return ss[i][j] == '#' && ss[i][j + 1] == '#' && ss[i + 1][j] == '#' &&
             ss[i + 1][j + 1] == '#';
    };
    const auto num_blocks = [&](u32 i, u32 j) -> u32 {
      u32 num = 0;
      if (check_block(i - 1, j - 1)) ++num;
      if (check_block(i - 1, j)) ++num;
      if (check_block(i - 1, j + 1)) ++num;
      if (check_block(i, j - 1)) ++num;
      if (check_block(i, j + 1)) ++num;
      if (check_block(i + 1, j - 1)) ++num;
      if (check_block(i + 1, j)) ++num;
      if (check_block(i + 1, j + 1)) ++num;
      return num;
    };
    const auto num_blocks2 = [&](u32 i, u32 j) -> u32 {
      u32 num = 0;
      if (check_block(i - 1, j - 1)) ++num;
      if (check_block(i - 1, j)) ++num;
      if (check_block(i, j - 1)) ++num;
      if (check_block(i, j)) ++num;
      return num;
    };
    const auto check = [&]() -> bool {
      for (u32 i = 0; i < h - 1; ++i) {
        for (u32 j = 0; j < w - 1; ++j) {
          if (check_block(i, j)) return false;
        }
      }
      return true;
    };

    u32 cnt = 0;
    while (!check()) {
      for (u32 k = 0; k <= 3; ++k) {
        for (u32 i = 0; i < h - 1; ++i) {
          for (u32 j = 0; j < w - 1; ++j) {
            if (!check_block(i, j)) continue;
            if (num_blocks(i, j) == k) {
              if (num_blocks2(i, j) == k + 1) {
                ss[i][j] = '.';
                ++cnt;
              } else if (num_blocks2(i, j + 1) == k + 1) {
                ss[i][j + 1] = '.';
                ++cnt;
              } else if (num_blocks2(i + 1, j) == k + 1) {
                ss[i + 1][j] = '.';
                ++cnt;
              } else if (num_blocks2(i + 1, j + 1) == k + 1) {
                ss[i + 1][j + 1] = '.';
                ++cnt;
              }
            }
          }
        }
      }
    }

    cout << cnt << endl;
  }
#endif
  // bit dp
  for (auto& [h, w, ss] : cases) {
    const u32 p2w = (1 << w);
    // dp[i][j] = i行目の状態がjで表せ、0 ~
    // i行目までブロックが存在しないようにするために必要な操作の最小値
    vector<vector<u32>> dp(h, vector<u32>(p2w, numeric_limits<u32>::max()));

    for (u32 j = 0; j < p2w; ++j) {
      u32 cnt = 0;
      bool possible = true;
      for (u32 k = 0; k < w; ++k) {
        const char c = ((j & (1u << k)) > 0) ? '#' : '.';
        if (ss[0][k] != c) {
          if (c == '.') {
            ++cnt;
          } else {
            possible = false;
            break;
          }
        }
      }
      if (possible) dp[0][j] = cnt;
    }

    for (u32 i = 1; i < h; ++i) {
      for (u32 j = 0; j < p2w; ++j) {
        u32 cnt = 0;
        {
          bool possible = true;
          for (u32 k = 0; k < w; ++k) {
            const char c = ((j & (1u << k)) > 0) ? '#' : '.';
            if (ss[i][k] != c) {
              if (c == '.') {
                ++cnt;
              } else {
                possible = false;
                break;
              }
            }
          }
          if (!possible) continue;
        }

        for (u32 k = 0; k < p2w; ++k) {
          if (dp[i - 1][k] == numeric_limits<u32>::max()) continue;
          bool possible = true;
          for (u32 l = 0; l < w - 1; ++l) {
            if (((k & (1u << l)) > 0) && ((k & (1u << (l + 1))) > 0) &&
                ((j & (1u << l)) > 0) && ((j & (1u << (l + 1))) > 0)) {
              possible = false;
              break;
            }
          }
          if (!possible) continue;
          dp[i][j] = min(dp[i][j], dp[i - 1][k] + cnt);
        }
      }
    }

    const u32 ans = *min_element(dp[h - 1].begin(), dp[h - 1].end());
    cout << ans << endl;
  }
}