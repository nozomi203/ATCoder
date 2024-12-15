#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s32 N;
  char c1, c2;
  string S;
  cin >> N >> c1 >> c2;
  cin >> S;
  for (char c : S) {
    cout << (c == c1 ? c1 : c2);
  }
  cout << endl;
}
