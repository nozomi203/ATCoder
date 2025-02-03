#include "util/common.h"

int main() {
  s64 N, Q;
  cin >> N >> Q;
  s64 ans{0};
  vector<s64> answers;
  vector<s64> cnt(N, 1);  // cnt[i] = count of pigeon in hole i;
  vector<s64> loc(N);     // log[i] = location of pigeon
  for (s64 i = 0; i < N; ++i) loc[i] = i;
  for (s64 i = 0; i < Q; ++i) {
    s64 q;
    cin >> q;
    if (q == 1) {
      s64 P, H;
      cin >> P >> H;
      --P;
      --H;
      s64 prev_loc = loc[P];
      loc[P] = H;
      if (cnt[prev_loc]-- == 2) --ans;
      if (++cnt[loc[P]] == 2) ++ans;
    } else {
      answers.push_back(ans);
    }
  }

  for (auto ans : answers) {
    cout << ans << endl;
  }
}