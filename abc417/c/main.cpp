#include "util/common.h"

/*
iを固定
iより大きいjのうち、j-Aj=Ai+iを満たすjの数を求める
*/

int main() {
  s64 n;
  cin >> n;
  vector<s64> as(n + 1);
  util::cin(as.begin() + 1, as.end());

  s64 cnt = 0;
  map<s64, s64> m;
  ++m[n - as[n]];
  for (s64 i = n - 1; i >= 1; --i) {
    cnt += m[i + as[i]];
    ++m[i - as[i]];
  }
  cout << cnt << endl;
}