#include "util/common.h"

int main() {
  s64 N;
  cin >> N;
  vector<string> S(N);
  for (s64 i = 0; i < N; ++i) {
    cin >> S[i];
  }
  sort(S.begin(), S.end(), [](const string& l, const string& r) {
    return l.length() < r.length();
  });
  for (const auto& str : S) {
    cout << str;
  }
  cout << endl;
}