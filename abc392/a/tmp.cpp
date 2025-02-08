#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 A1, A2, A3;
  cin >> A1 >> A2 >> A3;

  const auto check = [&]() {
    return A1 * A2 == A3 || A2 * A3 == A1 || A3 * A1 == A2;
  };
  cout << (check() ? "Yes" : "No") << endl;
}
