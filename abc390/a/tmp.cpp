#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  vector<s64> A(5);
  for (s64 i = 0; i < 5; ++i) cin >> A[i];

  const auto check = [&]() {
    for (s64 i = 0; i < 5; ++i) {
      if (A[i] != i + 1) return false;
    }
    return true;
  };

  bool yes{false};
  for (s64 i = 0; i < 4; ++i) {
    swap(A[i], A[i + 1]);
    if (check()) yes = true;
    swap(A[i], A[i + 1]);
  }

  cout << (yes ? "Yes" : "No") << endl;
}
