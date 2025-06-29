#include "../prime.h"

#include "../test.h"

int main() {
  TEST(util::is_prime(0), false);
  TEST(util::is_prime(1), false);
  TEST(util::is_prime(2), true);
  TEST(util::is_prime(5), true);
  TEST(util::is_prime(6), false);
  TEST(util::is_prime(67280421310721), true);

  const auto primes = util::get_primes(50);
  TEST(primes.size(), 15);
  TEST(primes[0], 2);
  TEST(primes[1], 3);
  TEST(primes[2], 5);
  TEST(primes[3], 7);
  TEST(primes[4], 11);
  TEST(primes[5], 13);
  TEST(primes[6], 17);
  TEST(primes[7], 19);
  TEST(primes[8], 23);
  TEST(primes[9], 29);
  TEST(primes[10], 31);
  TEST(primes[11], 37);
  TEST(primes[12], 41);
  TEST(primes[13], 43);
  TEST(primes[14], 47);
  const auto primes2 = util::get_primes(31, 50);
  TEST(primes2.size(), 5);
  TEST(primes2[0], 31);
  TEST(primes2[1], 37);
  TEST(primes2[2], 41);
  TEST(primes2[3], 43);
  TEST(primes2[4], 47);
  return 0;
}