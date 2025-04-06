#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  double p;
  cin >> p;

  const auto t = [&](double x) -> double { return x + p * powl(2, -x / 1.5); };

  double l{0}, r{p};
  while (r - l > 10e-9) {
    double new_l = l + (r - l) / 3;
    double new_r = r - (r - l) / 3;
    if (t(new_l) > t(new_r)) {
      l = new_l;
    } else {
      r = new_r;
    }
  }

  cout << fixed << setprecision(15) << t(l) << endl;
}
