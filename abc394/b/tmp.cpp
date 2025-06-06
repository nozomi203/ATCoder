#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  s64 N;
  cin >> N;
  vector<string> S(N);
  for (s64 i = 0; i < N; ++i) {
    cin >> S[i];
  }
  sort(S.begin(), S.end(), [](const string& l, const string& r) {
    return l.length() < r.length();
  });
  for (const auto& str : S) {
    cout << str;
  }
  cout << endl;
}
