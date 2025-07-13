#include <atcoder/modint>

#include "util/common.h"
#include "util/prime.h"

/*

a>bでなければいけない。そのような組み合わせの数は(n-2)*(n-1)/2
a,bが決まればおのずとcも決まる。b > c >= 0だが、c >0である必要がある。
a % b == 0であるような(a,b)の組み合わせの数を考える
aがbの倍数である

b = 2のとき、n/2 - 1
b = 3のとき、n/3 - 1

*/

using mint = atcoder::modint998244353;

int main() {
  size_t n;
  cin >> n;

  mint cnt = mint(n - 2) * mint(n - 1) / 2;
  size_t b = 2;
  while (b < n) {
    const size_t div = n / b;
    size_t b_end = n / div + 1;
    cnt -= (div - 1) * (b_end - b);
    b = b_end;
  }

  cout << cnt.val() << endl;
}