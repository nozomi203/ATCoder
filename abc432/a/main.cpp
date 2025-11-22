#include "util/common.h"

int main() {
  vector<s64> abc(3);
  util::cin(abc);
  sort(abc.begin(), abc.end(), greater());
  for (auto e : abc) cout << e;
  cout << endl;
}