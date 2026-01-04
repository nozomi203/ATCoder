#include "util/common.h"

int main() {
  s64 n;
  cin >> n;
  const s64 sqrtn = sqrt(n);

  vector<s64> cnts(n + 1);

  for (s64 x = 1; x <= sqrtn; ++x) {
    for (s64 y = x + 1; y <= sqrtn; ++y) {
      const s64 p = x * x + y * y;
      if (p > n) continue;
      cnts[p]++;
    }
  }

  vector<s64> answers;
  answers.reserve(n);
  for (s64 i = 1; i <= n; ++i) {
    if (cnts[i] == 1) answers.push_back(i);
  }

  cout << answers.size() << endl;
  for (s64 i = 0; i < answers.size(); ++i) {
    cout << answers[i];
    if (i < answers.size() - 1) cout << " ";
  }
  cout << endl;
}