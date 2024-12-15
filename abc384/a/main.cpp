#include "util/common.h"

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