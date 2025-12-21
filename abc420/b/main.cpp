#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<string> ss(n);
  util::cin(ss);
  vector<s64> cnts(n);
  for (s64 i = 0; i < m; ++i) {
    s64 cnt0 = 0;
    for (s64 j = 0; j < n; ++j) {
      if (ss[j][i] == '0') ++cnt0;
    }
    const char c = (cnt0 > 0 && cnt0 < n - cnt0) ? '0' : '1';
    for (s64 j = 0; j < n; ++j)
      if (ss[j][i] == c) ++cnts[j];
  }

  vector<s64> answers;
  const s64 mcnt = *max_element(cnts.begin(), cnts.end());
  for (s64 i = 0; i < n; ++i) {
    if (cnts[i] == mcnt) answers.push_back(i + 1);
  }
  for (s64 i = 0; i < answers.size(); ++i) {
    cout << answers[i];
    if (i < answers.size() - 1) cout << " ";
  }
  cout << endl;
}