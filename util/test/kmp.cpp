#include "../kmp.h"

#include "../test.h"

int main() {
  std::string s = "eababcfabeababcv";
  std::string t = "ababc";
  auto ans = util::kmp(s, t);
  TEST(ans.size(), 2);
  TEST(ans[0], 1);
  TEST(ans[1], 10);

  return 0;
}