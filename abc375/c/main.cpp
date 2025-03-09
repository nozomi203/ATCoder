#include "util/common.h"

int main() {
  s64 N;  // even
  cin >> N;
  vector<vector<char>> A(N, vector<char>(N)), B(N, vector<char>(N));
  for (s64 i{0}; i < N; ++i) {
    for (s64 j{0}; j < N; ++j) {
      cin >> A[i][j];
    }
  }

  for (s64 i{0}; i < N / 2; ++i) {
    const s64 rot{(i + 1) % 4};
    for (s64 j{i}; j < N - i; ++j) {
      if (rot == 0) {
        B[i][j] = A[i][j];
        B[N - 1 - j][i] = A[N - 1 - j][i];
        B[N - 1 - i][N - 1 - j] = A[N - 1 - i][N - 1 - j];
        B[j][N - 1 - i] = A[j][N - 1 - i];
      } else if (rot == 1) {
        B[i][j] = A[N - 1 - j][i];
        B[N - 1 - j][i] = A[N - 1 - i][N - 1 - j];
        B[N - 1 - i][N - 1 - j] = A[j][N - 1 - i];
        B[j][N - 1 - i] = A[i][j];
      } else if (rot == 2) {
        B[i][j] = A[N - 1 - i][N - 1 - j];
        B[N - 1 - j][i] = A[j][N - 1 - i];
        B[N - 1 - i][N - 1 - j] = A[i][j];
        B[j][N - 1 - i] = A[N - 1 - j][i];
      } else if (rot == 3) {
        B[i][j] = A[j][N - 1 - i];
        B[N - 1 - j][i] = A[i][j];
        B[N - 1 - i][N - 1 - j] = A[N - 1 - j][i];
        B[j][N - 1 - i] = A[N - 1 - i][N - 1 - j];
      }
    }
  }

  for (s64 i{0}; i < N; ++i) {
    for (s64 j{0}; j < N; ++j) {
      cout << B[i][j];
    }
    cout << endl;
  }
}