#include <atcoder/string>

#include "util/common.h"
/*
Sに含まれる文字がすべて異なる場合。
文字列長が奇数となるようなSのsuffix S'を選び、S'の先頭の文字を選べば先攻の勝ち
より一般的に、Sのsuffixのうち、任意のsuffixの部分文字列に含まれないものの集合をUとする。
ＴはUに含まれる要素のprefixでしかありえない

*/

int main() {
  s64 t;
  cin >> t;
  vector<string> ss(t);
  util::cin(ss);

  const auto check = [](const string& s) -> bool {

  };

  for (const auto& s : ss) {
    cout << (check(s) ? "Alice" : "Bob") << endl;
  }
}