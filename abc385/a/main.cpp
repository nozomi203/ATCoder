#include "util/common.h"

int main() {
  s64 A, B, C;
  cin >> A >> B >> C;
  cout << ((A + B == C || B + C == A || C + A == B || (A == B && B == C))
               ? "Yes"
               : "No")
       << endl;
}