#include "util/common.h"

int main() {
  s64 h, w;
  cin >> h >> w;
  vector<string> ss(h);
  util::cin(ss);
  vector<s64> numfs(w);
  s64 sumf = 0;
  for (s64 i = 0; i < h; ++i) {
    for (s64 j = 0; j < w; ++j) {
      if (ss[i][j] == '#') {
        numfs[j]++;
        sumf++;
      }
    }
  }

  s64 maxf = 0;
  for (s64 i = 0; i < h; ++i) {
    for (s64 j = 0; j < w; ++j) {
      if (ss[i][j] == '#') {
        --numfs[j];
        --sumf;
      } else {
        ++numfs[j];
        ++sumf;
      }
    }

    s64 minf = numeric_limits<s64>::max();
    for (s64 j = 0; j < w; ++j) {
      s64 f = sumf - numfs[j] + (h - numfs[j]);
      minf = min(minf, f);
    }
    maxf = max(maxf, minf);

    for (s64 j = 0; j < w; ++j) {
      if (ss[i][j] == '#') {
        ++numfs[j];
        ++sumf;
      } else {
        --numfs[j];
        --sumf;
      }
    }
  }

  cout << maxf << " " << h * w - maxf << endl;
}