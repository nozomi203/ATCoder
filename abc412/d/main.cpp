#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<pair<s64, s64>> abs(m);
  util::cin(abs);
  vector<vector<bool>> cnct(n + 1, vector<bool>(n + 1, false));
  for (auto [a, b] : abs) {
    cnct[a][b] = cnct[b][a] = true;
  }

  vector<s64> idxs(n);
  iota(idxs.begin(), idxs.end(), 1);

  s64 ans = numeric_limits<s64>::max();
  do {
    // one loop
    {
      s64 num_remove = m;
      s64 num_add = 0;
      for (s64 i = 0; i < n; ++i) {
        const auto a = idxs[i];
        const auto b = idxs[(i + 1) % n];
        if (cnct[a][b]) {
          --num_remove;
        } else {
          ++num_add;
        }
      }
      s64 cnt = num_remove + num_add;
      ans = min(ans, cnt);
    }
    // two loops(3,x)
    if (n >= 6) {
      s64 num_remove = m;
      s64 num_add = 0;
      for (s64 i = 0; i < 3; ++i) {
        const auto a = idxs[i];
        const auto b = idxs[(i + 1) % 3];
        if (cnct[a][b]) {
          --num_remove;
        } else {
          ++num_add;
        }
      }
      for (s64 i = 0; i < n - 3; ++i) {
        const auto a = idxs[i + 3];
        const auto b = idxs[i + 4 < n ? i + 4 : 3];
        if (cnct[a][b]) {
          --num_remove;
        } else {
          ++num_add;
        }
      }
      s64 cnt = num_remove + num_add;
      ans = min(ans, cnt);
    }
    // two loop(4,4)
    if (n == 8) {
      s64 num_remove = m;
      s64 num_add = 0;
      for (s64 i = 0; i < 4; ++i) {
        const auto a = idxs[i];
        const auto b = idxs[(i + 1) % 4];
        if (cnct[a][b]) {
          --num_remove;
        } else {
          ++num_add;
        }
      }
      for (s64 i = 0; i < n - 4; ++i) {
        const auto a = idxs[i + 4];
        const auto b = idxs[i + 5 < n ? i + 5 : 4];
        if (cnct[a][b]) {
          --num_remove;
        } else {
          ++num_add;
        }
      }
      s64 cnt = num_remove + num_add;
      ans = min(ans, cnt);
    }

  } while (next_permutation(idxs.begin(), idxs.end()));

  cout << ans << endl;
}