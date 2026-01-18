#include "util/common.h"

int main() {
  s64 n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  s64 q;
  cin >> q;
  vector<string> ws(q);
  util::cin(ws);

  set<char> set_s, set_t;
  for (char c : s) set_s.emplace(c);
  for (char c : t) set_t.emplace(c);

  for (string& w : ws) {
    bool b_s = true, b_t = true;
    for (char c : w) {
      if (!set_s.contains(c)) b_s = false;
      if (!set_t.contains(c)) b_t = false;
    }
    if (b_s && !b_t) {
      cout << "Takahashi" << endl;
    } else if (!b_s && b_t) {
      cout << "Aoki" << endl;
    } else {
      cout << "Unknown" << endl;
    }
  }
}