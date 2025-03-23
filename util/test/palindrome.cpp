#include "../palindrome.h"

#include "../test.h"

int main() {
  std::string s = "abacababa";
  auto r = util::palindrome_radius(s);
  TEST(r[0], 1);
  TEST(r[1], 2);
  TEST(r[2], 1);
  TEST(r[3], 4);
  TEST(r[4], 1);
  TEST(r[5], 2);
}