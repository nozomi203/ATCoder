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
  vector<vector<char>> buff(N, vector<char>(N, '.'));
  for (s64 i = 0; i <= (N - 1) / 2; i += 2) {
    for (s64 j = 0; j < N - 2 * i; ++j) {
      buff[i + j][i] = '#';
      buff[i + j][N - 1 - i] = '#';
      buff[i][i + j] = '#';
      buff[N - 1 - i][i + j] = '#';
    }
  }

  for (s64 i = 0; i < N; ++i) {
    for (s64 j = 0; j < N; ++j) {
      cout << buff[i][j];
    }
    cout << endl;
  }
}
