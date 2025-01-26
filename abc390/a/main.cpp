#include "util/common.h"

int main() {
  vector<s64> A(5);
  for (s64 i = 0; i < 5; ++i) cin >> A[i];

  const auto check = [&]() {
    for (s64 i = 0; i < 5; ++i) {
      if (A[i] != i + 1) return false;
    }
    return true;
  };

  bool yes{false};
  for (s64 i = 0; i < 4; ++i) {
    swap(A[i], A[i + 1]);
    if (check()) yes = true;
    swap(A[i], A[i + 1]);
  }

  cout << (yes ? "Yes" : "No") << endl;
}