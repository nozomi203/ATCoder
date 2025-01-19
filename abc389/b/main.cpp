#include "util/common.h"

int main() {
  s64 X;
  cin >> X;
  s64 fact{1};
  s64 n{1};
  while (fact != X) {
    ++n;
    fact *= n;
  }
  cout << n << endl;
}