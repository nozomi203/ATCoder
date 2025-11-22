#include "util/common.h"

int main() {
  string x;
  cin >> x;
  s64 cnt_zero = 0;
  vector<char> cs;
  for (auto c : x) {
    if (c == '0') {
      ++cnt_zero;
    } else {
      cs.push_back(c);
    }
  }
  sort(cs.begin(), cs.end());
  assert(!cs.empty());
  cout << cs.front();
  for (s64 i = 0; i < cnt_zero; ++i) cout << 0;
  for (s64 i = 1; i < cs.size(); ++i) cout << cs[i];
  cout << endl;
}