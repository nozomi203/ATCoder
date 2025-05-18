#pragma once
#include <cstdint>
#include <random>
#include <string>
#include <vector>

namespace util {
class rolling_hash {
 public:
  rolling_hash(const std::string& s, uint64_t base)
      : m_h(s.size() + 1), m_pow_base(s.size() + 1, 1) {
    for (size_t i{1}; i < m_h.size(); ++i)
      m_h[i] = calc_mod(mul(m_h[i - 1], base) + s[i - 1]);
    for (size_t i{1}; i < m_pow_base.size(); ++i)
      m_pow_base[i] = calc_mod(mul(m_pow_base[i - 1], base));
  }
  rolling_hash(const std::string& s)
      : rolling_hash(s, std::invoke([]() -> uint64_t {
                       std::random_device seed_gen;
                       std::mt19937 engine(seed_gen());
                       std::uniform_int_distribution<uint64_t> dist(2, mod - 2);
                       return dist(engine);
                     })) {}

 public:
  uint64_t get_hash(size_t l, size_t r) {
    return calc_mod(m_h[r] + mod * 4ULL - mul(m_h[l], m_pow_base[r - l]));
  }

  size_t size() const { return m_h.size() - 1; }

 private:
  uint64_t mul(uint64_t lhs, uint64_t rhs) {
    const uint64_t lu{lhs >> 31};
    const uint64_t ld{lhs & ((1ULL << 31) - 1)};
    const uint64_t ru{rhs >> 31};
    const uint64_t rd{rhs & ((1ULL << 31) - 1)};
    const uint64_t mid{ld * ru + lu * rd};
    const uint64_t midu{mid >> 30};
    const uint64_t midd{mid & ((1ULL << 30) - 1)};
    return lu * ru * 2ULL + midu + (midd << 31) + ld * rd;
  }

  uint64_t calc_mod(uint64_t x) {
    const uint64_t xu{x >> 61};
    const uint64_t xd{x & ((1ULL << 61) - 1)};
    const uint64_t ret{xu + xd};
    return ret >= mod ? ret - mod : ret;
  }

 private:
  static constexpr uint64_t mod = (1ULL << 61) - 1;

 private:
  std::vector<uint64_t> m_h;
  std::vector<uint64_t> m_pow_base;
};
}  // namespace util