#include "util/common.h"

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