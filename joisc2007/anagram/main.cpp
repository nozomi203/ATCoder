#include "util/common.h"

/*
heart 55
aehrt 1
与えられた文字列より辞書順で先に来るものを数え上げる
1文字目が辞書順で先に来ている任意の文字列
1文字目が一致して2文字目が辞書順で先に来ている任意の文字列
1文字目と2文字目が一致して3文字目が辞書順で先に来ている任意の文字列
...
先頭から数えて一致している文字数についてループする
一致している文字列の集合をSとしたとき、~Sのアナグラムの種類数f(S)が答え
文字列の重複に注意する
*/

size_t fact(size_t n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}

int main() {
  string s;
  cin >> s;
  size_t cnt{s.size()};
  map<char, size_t> c_cnts;
  for (char c : s) ++c_cnts[c];

  size_t ans{0};
  for (size_t i{0}; i < s.size(); ++i) {
    size_t add{fact(cnt)};
    for (auto [c, c_cnt] : c_cnts) add /= fact(c_cnt);
    for (auto [c, c_cnt] : c_cnts) {
      if (c >= s[i]) continue;
      size_t tmp{add};
      tmp *= c_cnt;
      tmp /= cnt;
      ans += tmp;
    }
    --cnt;
    if (--c_cnts[s[i]] == 0) c_cnts.erase(s[i]);
  }

  cout << ans + 1 << endl;
}