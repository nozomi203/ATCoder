#include "util/common.h"

int main() {
  for (int n :
       views::iota(1, 10) | views::filter([](int i) { return i % 2 == 1; })) {
    cout << n << endl;
  }
}