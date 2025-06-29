#include <atcoder/modint>

#include "util/common.h"

/*
タンスに戻すのは枚数が少ない方
p[i] = i回目で操作を完了する確率
q[i][j] = i回目でjの靴下を持っている確率
p[0] = num[c] / num_all
p[1] = []
*/

int main() {
  s64 n, c;
  cin >> n >> c;
  vector<s64> as(n);
  util::cin(as);
}