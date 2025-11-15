#include "util/common.h"

int main() {
  s64 a, b, c, d;
  util::cin(a, b, c, d);

  const auto check = [&]() {
    if (c >= a) {
      return d >= b;
    }
    return true;
  };

  cout << (check() ? "No" : "Yes") << endl;
}