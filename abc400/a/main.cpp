#include "util/common.h"

int main() {
  s64 a;
  cin >> a;
  cout << (400 % a ? -1 : 400 / a) << endl;
}