#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));

  const auto check = [&]() {
    constexpr auto kMax = numeric_limits<s64>::max();
    constexpr auto kMin = numeric_limits<s64>::min();
    pair<s64, s64> bpos_min{kMax, kMax}, bpos_max{kMin, kMin};
    for (s64 i = 0; i < H; ++i) {
      string S;
      cin >> S;
      for (s64 j = 0; j < W; ++j) {
        char c = S[j];
        grid[i][j] = c;
        if (c == '#') {
          bpos_min.first = min(bpos_min.first, i);
          bpos_min.second = min(bpos_min.second, j);
          bpos_max.first = max(bpos_max.first, i);
          bpos_max.second = max(bpos_max.second, j);
        }
      }
    }

    for (s64 i = bpos_min.first; i <= bpos_max.first; ++i) {
      for (s64 j = bpos_min.second; j <= bpos_max.second; ++j) {
        if (grid[i][j] == '.') return false;
      }
    }

    return true;
  };

  cout << (check() ? "Yes" : "No") << endl;
}
