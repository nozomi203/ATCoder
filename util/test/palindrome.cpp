#include "../palindrome.h"

#include "../test.h"

int main() {
  std::string s = "abacababa";
  auto l = util::palindrome_length(s);
  TEST(l[0].first, 1);
  TEST(l[0].second, 0);
  TEST(l[1].first, 3);
  TEST(l[1].second, 0);
  TEST(l[2].first, 1);
  TEST(l[2].second, 0);
  TEST(l[3].first, 7);
  TEST(l[3].second, 0);
  TEST(l[4].first, 1);
  TEST(l[4].second, 0);
  TEST(l[5].first, 3);
  TEST(l[5].second, 0);
}