#include "util/common.h"

int main() {
  s64 A1, A2, A3;
  cin >> A1 >> A2 >> A3;

  const auto check = [&]() {
    return A1 * A2 == A3 || A2 * A3 == A1 || A3 * A1 == A2;
  };
  cout << (check() ? "Yes" : "No") << endl;
}