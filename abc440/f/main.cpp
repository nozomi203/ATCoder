#include <atcoder/math>

/*
丁寧な馬の後に来る馬の満足度の機嫌の総和を最大化する。
丁寧度1の馬を満足度の降順に、
丁寧度2の馬を満足度の昇順に並べる。
それぞれの列をP,Qとする。
Q[0]はP[|P|-1]の右に挿入、
その後、Q[i+1]をP[i+1]の左側に、Q[i+1] > P[i+1]が満たされる範囲で挿入する。
Pが単調増加、Qが単調減少することから、Q[i+1]>P[i+1]を満たす最大のiはO(logN)で計算できる。
あとは、クエリに対するP,Qの更新が高速にできればいい。

*/

#include "util/common.h"
int main() {
  s64 n, q;
  cin >> n >> q;
  vector<pair<s64, s64>> abs(n);
  vector<tuple<s64, s64, s64>> wxys(q);
}