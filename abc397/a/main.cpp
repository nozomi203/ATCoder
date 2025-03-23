#include "util/common.h"

int main() {
  float x;
  cin >> x;
  cout << (x >= 38.0f ? 1 : (x >= 37.5f ? 2 : 3)) << endl;
}