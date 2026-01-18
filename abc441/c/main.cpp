#include "util/common.h"
/*
多い方のカップから条件を満たすまで飲めばいい
このとき最も飲む回数が多くなるのは、日本酒が全部少ないカップに入っていた場合。
そのつもりで計算をする
*/
int main() {
  s64 n, k, x;
  cin >> n >> k >> x;
  vector<s64> as(n);
  util::cin(as);
  sort(as.begin(), as.end(), greater());
  const auto get = [&]() -> s64 {
    s64 sum = 0;
    s64 num = n - k;
    for (s64 i = n - k; i < n; ++i) {
      sum += as[i];
      ++num;
      if (sum >= x) return num;
    }
    return -1;
  };
  cout << get() << endl;
}