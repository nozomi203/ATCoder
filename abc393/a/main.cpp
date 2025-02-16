#include "util/common.h"

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  bool b1 = s1 == "sick" ? true : false;
  bool b2 = s2 == "sick" ? true : false;
  const auto get_ans = [&]() {
    if (b1 && b2) return 1;
    if (b1 && !b2) return 2;
    if (!b1 && b2) return 3;
    return 4;
  };

  cout << get_ans() << endl;
}