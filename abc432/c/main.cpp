#include "util/common.h"

/*
それぞれの子供に配る飴の数が決まっており、その個数だけ配った時の飴の重さが等しくなるようにする。
なるべく、大きな飴をたくさん与えるようにする

ある子供に対してある飴の配り方をした場合、そこから重さを減らすには大きな飴を小さな飴に変更するしかない。
つまり、重さはY-Xずつしか減らせない。
全員が最大限大きな飴をもらっている状態から、条件を満たすまで重さを減らしていくと考える
*/

int main() {
  s64 n, x, y;
  cin >> n >> x >> y;
  vector<s64> as(n);
  util::cin(as);

  const auto solve = [&]() -> s64 {
    s64 numy = 0;
    vector<pair<s64, s64>> dp(n);
    for (s64 i = 0; i < n; ++i) {
      dp[i] = make_pair(y * as[i], as[i]);
      numy += as[i];
    }
    sort(dp.begin(), dp.end(), greater());

    s64 minnumy = dp.front().second;
    for (s64 i = 0; i < dp.size() - 1; ++i) {
      auto [w0, numy0] = dp[i];
      auto [w1, numy1] = dp[i + 1];
      minnumy = min(minnumy, numy0);
      const s64 diffw = w0 - w1;
      const s64 diffyx = y - x;
      if (diffw % diffyx != 0) return -1;
      const s64 cnt_replace = diffw / diffyx;
      if (cnt_replace > minnumy) return -1;
      minnumy -= cnt_replace;
      numy -= (i + 1) * cnt_replace;
    }
    return numy;
  };
  cout << solve() << endl;
}
