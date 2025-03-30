#include "util/common.h"

int main() {
  string s;
  cin >> s;
  cout << (s.ends_with("san") ? "Yes" : "No") << endl;
}