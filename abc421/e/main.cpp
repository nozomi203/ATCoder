#include "util/common.h"

/*
f(i,j) =
あとi回サイコロを振ることができるとき、キープしているダイスの出目の多重集合がjであるときの期待値の最大値
求めたいのは、f(3, {})

f(i,S)のとき、振れるサイコロの数は5 - |S|
振ったサイコロが取れる状態の数は6 ^ (5 - |S|)
*/
int main() {
  map<s64, s64> ma;
  for (s64 i = 0; i < 6; ++i) {
    s64 a;
    cin >> a;
    ++ma[a];
  }

  vector<multiset<double>> dp(4);
  const s64 num = ma.size();
  
}