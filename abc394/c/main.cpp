#include "util/common.h"

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