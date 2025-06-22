#include <atcoder/modint>

#include "util/common.h"
/*
bitdp?
dp[b] = bで表現される頂点集合に含まれるサイクルの数
*/

using mint = atcoder::modint998244353;

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<pair<size_t, size_t>> uvs(m);
  util::cin(uvs);
  for (auto& [u, v] : uvs) {
    --u;
    --v;
  }

  vector<vector<size_t>> c(n, vector<size_t>(n, 0));
  for (auto& [u, v] : uvs) {
    ++c[u][v];
    ++c[v][u];
  }

  mint ans = 0;
  /*
  サイクルの中で最大の頂点をsで固定し、それぞれに対して問題を解く
  */
  for (size_t s = 2; s < n; ++s) {
    // m... the largest number included in the cycle
    /*
    dp[b][i] =
    bで表現される頂点集合に含まれる頂点をそれぞれsからスタートして1回ずつ通過し、iで終わるサイクルの数
    */
    vector dp(1 << (s + 1), vector<mint>(s + 1));
    dp[1 << s][s] = 1;
    /*
    b...頂点集合。1<<sから始めることで、sを含むことを保証する
    */
    for (size_t b = (1 << s); b < (1 << (s + 1)); ++b) {
      /*
      i...サイクルの終着点
      */
      for (size_t i = 0; i <= s; ++i) {
        /*
        終着点はbに含まれるものしか考えない
        */
        if (!(b & (1 << i))) continue;
        /*
        bに含まれる頂点のうち、3つ以上が選ばれている場合は、終点iと視点sを結ぶことでサイクルができるため答えを加算する。
        bの更新はこれより前に済んでいるため、ここで加算してしまっておｋ
        */
        if (std::popcount(b) >= 3) {
          const auto add = c[i][s] * dp[b][i];
          ans += add;
        }
        /*
        次の終着点をj選択して更新する
        */
        for (size_t j = 0; j <= s; ++j) {
          /*
          すでにbに含まれている頂点は終着点にはならない
          */
          if (b & (1ULL << j)) continue;
          const auto add = dp[b][i] * c[i][j];
          dp[b | (1ULL << j)][j] += add;
        }
      }
    }
  }

  /*
  頂点数2のサイクルは特別扱い
  */
  for (size_t i = 0; i < n - 1; ++i) {
    for (size_t j = i + 1; j < n; ++j) {
      if (i == j) continue;
      if (c[i][j] < 2) continue;
      const auto add = c[i][j] * (c[i][j] - 1);
      ans += add;
    }
  }

  ans /= 2;
  cout << ans.val() << endl;
}