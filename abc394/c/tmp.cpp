#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  string S;
  cin >> S;
  for (s64 i = 0; i < S.size() - 1; ++i) {
    if (S[i] == 'W' && S[i + 1] == 'A') {
      s64 j = i;
      while (j >= 0 && S[j] == 'W' && S[j + 1] == 'A') {
        S[j] = 'A';
        S[j + 1] = 'C';
        --j;
      }
    }
  }
  cout << S << endl;
}
