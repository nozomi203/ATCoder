#include "util/common.h"

int main() {
  s64 A, B, C, D;
  cin >> A >> B >> C >> D;
  map<s64, s64> m;
  m[A]++;
  m[B]++;
  m[C]++;
  m[D]++;
  cout << (m.size() == 2 ? "Yes" : "No") << endl;
}