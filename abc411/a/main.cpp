#include "util/common.h"

int main() {
  string p;
  size_t l;
  cin >> p >> l;
  cout << (p.size() >= l ? "Yes" : "No") << endl;
}