#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  if (n % 2) {
    for (s64 i{0}; i < n / 2; ++i) cout << '-';
    cout << '=';
    for (s64 i{0}; i < n / 2; ++i) cout << '-';
  } else {
    for (s64 i{0}; i < n / 2 - 1; ++i) cout << '-';
    cout << "==";
    for (s64 i{0}; i < n / 2 - 1; ++i) cout << '-';
  }
  cout << endl;
}