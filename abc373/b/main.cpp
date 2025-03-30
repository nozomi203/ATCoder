#include "util/common.h"

int main() {
  string s;
  cin >> s;
  map<char, s64> m;
  for (s64 i{0}; i < 26; ++i) {
    m[s[i]] = i;
  }
  s64 dist{0};
  s64 l{m['A']};
  for (char c{'B'}; c <= 'Z'; ++c) {
    dist += abs(m[c] - l);
    l = m[c];
  }
  cout << dist << endl;
}