#include "util/common.h"

int main() {
  s64 N;
  cin >> N;
  s64 A{0};
  for (s64 i = 0; i < N; ++i) {
    s64 tmp;
    cin >> tmp;
    if (tmp <= A) {
      cout << "No" << endl;
      return 0;
    }
    A = tmp;
  }
  cout << "Yes" << endl;
}