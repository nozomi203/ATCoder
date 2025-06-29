#pragma once
#include <cassert>
#include <cmath>
#include <cstdint>
#include <numeric>
#include <vector>

namespace util {
inline bool is_prime(size_t n) {
  if (n < 2) return false;
  const size_t sqrtn = std::sqrt(n);
  for (size_t i = 2; i <= sqrtn; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

/// @brief get all primes less than n
/// @param n
/// @return
inline std::vector<size_t> get_primes(size_t n) {
  std::vector<bool> isps(n, true);
  const size_t sqrtn = std::ceil(std::sqrt(n));
  for (size_t i = 2; i <= sqrtn; ++i) {
    if (!isps[i]) continue;
    for (size_t val = i * 2; val < n; val += i) isps[val] = false;
  }

  std::vector<size_t> ret;
  for (size_t i = 2; i < n; ++i) {
    if (isps[i]) ret.push_back(i);
  }
  return ret;
}

/// @brief get all primes in range [l,r)
/// @param l
/// @param r
/// @return
inline std::vector<size_t> get_primes(size_t l, size_t r) {
  const size_t sqrtr = std::ceil(std::sqrt(r));
  std::vector<bool> isps(sqrtr, true);
  for (size_t i = 2; i < sqrtr; ++i) {
    if (!isps[i]) continue;
    for (size_t val = i * 2; val < sqrtr; val += i) isps[val] = false;
  }

  std::vector<bool> isps2(r - l, true);
  for (size_t i = 2; i < sqrtr; ++i) {
    if (!isps[i]) continue;
    for (size_t j = i * ((l + i - 1) / i); j < r; j += i) {
      isps2[j - l] = false;
    }
  }

  std::vector<size_t> ret;
  for (size_t i = l; i < r; ++i) {
    if (isps2[i - l]) ret.push_back(i);
  }
  return ret;
}

/// @brief get all primes in range [l,r)
/// @param l
/// @param r
/// @return
inline std::vector<size_t> get_min_factors(size_t l, size_t r) {
  assert(l < r);
  const size_t sqrtr = std::ceil(std::sqrt(r));
  std::vector<bool> isps(sqrtr, true);
  for (size_t i = 2; i < sqrtr; ++i) {
    if (!isps[i]) continue;
    for (size_t val = i * 2; val < sqrtr; val += i) isps[val] = false;
  }

  std::vector<size_t> min_factors(r - l);
  std::iota(min_factors.begin(), min_factors.end(), l);
  for (size_t i = 2; i < sqrtr; ++i) {
    if (!isps[i]) continue;
    for (size_t j = i * ((l + i - 1) / i); j < r; j += i) {
      min_factors[j - l] = std::min(min_factors[j - l], i);
    }
  }

  return min_factors;
}

}  // namespace util
