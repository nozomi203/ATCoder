#include "util/common.h"

int main() {
  s64 h, w, n;
  cin >> h >> w >> n;
  vector<vector<s64>> ass(h, vector<s64>(w));
  util::cin(ass);
  vector<s64> bs(n);
  util::cin(bs);

  vector<s64> cnts(h);

  for (auto b : bs) {
    for (s64 i = 0; i < h; ++i) {
      for (s64 j = 0; j < w; ++j) {
        if (ass[i][j] == b) ++cnts[i];
      }
    }
  }

  cout << *max_element(cnts.begin(), cnts.end()) << endl;
}