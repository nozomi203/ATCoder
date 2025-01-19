#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N, M, A, B;
  cin >> N >> M >> A >> B;
  vector<pair<s64, s64>> lr(M + 2);
  for (s64 i = 1; i < M + 1; ++i) {
    cin >> lr[i].first >> lr[i].second;
  }
  lr[0] = {0, 0};
  lr[M + 1] = {N + 1, N + 1};

  const auto check = [&]() {
    if (A == B) {
      if ((N - 1) % A > 0) return false;
      for (auto [l, r] : lr) {
        if (r - l + 1 >= A) return false;
        if ((l - 1) % A == 0) return false;
        if ((l - 1) % A > (r - 1) % A) return false;
      }
      return true;
    } else {
      const s64 t = B * B - 3 * B + 2;
      vector<bool> dp(t, false);  // dp[i] = can move by i;
      dp[0] = true;
      for (s64 i = 1; i < t; ++i) {
        for (s64 j = A; j <= B; ++j) {
          if (i - j >= 0) {
            if (dp[i - j]) {
              dp[i] = true;
              break;
            }
          }
        }
      }
      const auto can_move = [&](s64 s) -> bool {
        if (s >= t) return true;
        if (s < 0) return false;
        return dp[s];
      };

      unordered_set<s64> reach;
      reach.emplace(1);
      for (s64 i = 1; i < M + 2; ++i) {
        const auto l = lr[i - 1].second + 1;
        const auto r = lr[i].first - 1;
        const auto b_x = l;
        const auto e_x = min(r, b_x + B);
        const auto b_y = max(l, r - B);
        const auto e_y = r;
        for (s64 j = b_x; j <= e_x; ++j) {
          for (s64 k = A; k <= B; ++k) {
            if (reach.count(j - k) > 0) {
              reach.emplace(j);
              break;
            }
          }
        }
        for (s64 j = b_y; j <= e_y; ++j) {
          for (s64 k = A; k <= B; ++k) {
            if (reach.count(j - k) > 0) {
              reach.emplace(j);
              break;
            }
          }
          for (s64 k = b_x; k <= e_x; ++k) {
            if (reach.count(k) > 0 && can_move(j - k)) {
              reach.emplace(j);
              break;
            }
          }
        }
      }

      return reach.count(N) > 0;
    }
  };

  cout << (check() ? "Yes" : "No") << endl;
}
