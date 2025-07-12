#include "util/common.h"

int main() {
  s32 n, w, h;
  cin >> n >> w >> h;
  vector<vector<s32>> css(h, vector<s32>(w));
  util::cin(css);

  vector<vector<vector<s32>>> ccntsss(
      h + 1, vector<vector<s32>>(w + 1, vector<s32>(n + 1)));
  vector<s32> minis(n + 1, h), maxis(n + 1, 0), minjs(n + 1, w),
      maxjs(n + 1, 0);

  for (s32 i = 1; i <= h; ++i) {
    for (s32 j = 1; j <= w; ++j) {
      const auto c = css[i - 1][j - 1];
      ++ccntsss[i][j][c];
      minis[c] = min(minis[c], i);
      maxis[c] = max(maxis[c], i);
      minjs[c] = min(minjs[c], j);
      maxjs[c] = max(maxjs[c], j);
    }
  }

  for (s32 i = 2; i <= h; ++i) {
    for (s32 j = 1; j <= w; ++j) {
      for (s32 k = 0; k <= n; ++k) {
        ccntsss[i][j][k] += ccntsss[i - 1][j][k];
      }
    }
  }
  for (s32 j = 2; j <= w; ++j) {
    for (s32 i = 1; i <= h; ++i) {
      for (s32 k = 0; k <= n; ++k) {
        ccntsss[i][j][k] += ccntsss[i][j - 1][k];
      }
    }
  }

  const auto get_cnt = [&](s32 mini, s32 minj, s32 maxi, s32 maxj,
                           s32 c) -> s32 {
    return ccntsss[maxi][maxj][c] - ccntsss[maxi][minj - 1][c] -
           ccntsss[mini - 1][maxj][c] + ccntsss[mini - 1][minj - 1][c];
  };

  vector<s32> seqs;
  list<s32> idxs;
  for (s32 c = 1; c <= n; ++c) idxs.emplace_back(c);
  while (!idxs.empty()) {
    bool found = false;
    for (auto it = idxs.begin(); it != idxs.end();) {
      const auto c = *it;
      const auto mini = minis[c];
      const auto minj = minjs[c];
      const auto maxi = maxis[c];
      const auto maxj = maxjs[c];
      const auto cntc = get_cnt(mini, minj, maxi, maxj, c);
      const auto cnt0 = get_cnt(mini, minj, maxi, maxj, 0);
      const auto s = (maxi - mini + 1) * (maxj - minj + 1);
      if (cntc + cnt0 == s) {
        for (s32 j = 0; j <= w; ++j) {
          for (s32 i = 0; i <= h; ++i) {
            ccntsss[i][j][0] += ccntsss[i][j][c];
            ccntsss[i][j][c] = 0;
          }
        }
        found = true;
        seqs.push_back(c);

        it = idxs.erase(it);
      } else {
        ++it;
      }
    }
    if (!found) {
      for (auto idx : idxs) seqs.push_back(idx);
      idxs.clear();
    }
  }

  reverse(seqs.begin(), seqs.end());
  for (s32 i = 0; i < n; ++i) {
    cout << seqs[i];
    if (i < n - 1) cout << " ";
  }
  cout << endl;
}