#include "util/common.h"

int main() {
  s64 N, M;
  cin >> N >> M;
  vector<vector<char>> S(N + 1, vector<char>(N + 1)),
      T(M + 1, vector<char>(M + 1));
  for (s64 i = 1; i <= N; ++i) {
    string str;
    cin >> str;
    for (s64 j = 1; j <= N; ++j) {
      S[i][j] = str[j - 1];
    }
  }
  for (s64 i = 1; i <= M; ++i) {
    string str;
    cin >> str;
    for (s64 j = 1; j <= M; ++j) {
      T[i][j] = str[j - 1];
    }
  }

  const auto check = [&](s64 a, s64 b) -> bool {
    for (s64 i = 1; i <= M; ++i) {
      for (s64 j = 1; j <= M; ++j) {
        if (S[a + i - 1][b + j - 1] != T[i][j]) return false;
      }
    }
    return true;
  };

  for (s64 a = 1; a <= N - M + 1; ++a) {
    for (s64 b = 1; b <= N - M + 1; ++b) {
      if (check(a, b)) {
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
}