#include "util/common.h"

/*
正方形の中に注目しているセルを除いて3色あるなら、何色に変えてもいい
2色なら、それ以外の色でないといけない
1色なら、そもそもカウントの対象外
*/

int main() {
  s64 n, k;
  cin >> n >> k;
  vector<vector<s64>> ass(n, vector<s64>(n));
  util::cin(ass);

  const auto check_range = [&](s64 i, s64 j) -> bool {
    return 0 <= i && i < n && 0 <= j && j < n;
  };

  const auto get_s = [&](s64 i, s64 j) {
    set<s64> s;
    if (check_range(i, j)) s.emplace(ass[i][j]);
    if (check_range(i, j + 1)) s.emplace(ass[i][j + 1]);
    if (check_range(i + 1, j)) s.emplace(ass[i + 1][j]);
    if (check_range(i + 1, j + 1)) s.emplace(ass[i + 1][j + 1]);
    return s;
  };

  const auto is_c = [&](s64 i, s64 j) -> bool {
    return get_s(i, j).size() >= 3;
  };

  const auto get_ccnt = [&](s64 i, s64 j) -> s64 {
    s64 ret = 0;
    if (is_c(i - 1, j - 1)) ++ret;
    if (is_c(i - 1, j)) ++ret;
    if (is_c(i, j - 1)) ++ret;
    if (is_c(i, j)) ++ret;
    return ret;
  };

  s64 cnt_c = 0;
  for (s64 i = 0; i < n - 1; ++i) {
    for (s64 j = 0; j < n - 1; ++j) {
      if (is_c(i, j)) ++cnt_c;
    }
  }

  /*
  各マスを塗り替えた時のカラフル度の変化の最大を求める
  塗り替え先は候補がありすぎるので、塗り替えてはダメな色を管理する
  すでにカラフル→カラフルを保つために塗り替えてはダメな色
  カラフルでない→カラフルにするために選んではいけない色
  塗り替え先がある場合はその色を選択し、ない場合は塗り替えてはダメな色の中からましなやつを選ぶ
  */

  s64 dcmax = 0;
  for (s64 i = 0; i < n; ++i) {
    for (s64 j = 0; j < n; ++j) {
      const s64 ccnt = get_ccnt(i, j);
      set<s64> cs;
      for (s64 di = -1; di <= 1; ++di) {
        for (s64 dj = -1; dj <= 1; ++dj) {
          if (i + di < 0 || i + di >= n || j + dj < 0 || j + dj >= n) continue;
          cs.emplace(ass[i + di][j + dj]);
        }
      }

      if (cs.size() < k) {
        cs.emplace(-1);
      }
      for (auto c : cs) {
        s64 tmp = ass[i][j];
        ass[i][j] = c;
        dcmax = max(dcmax, get_ccnt(i, j) - ccnt);
        ass[i][j] = tmp;
      }
    }
  }

  cout << cnt_c + dcmax << endl;
}