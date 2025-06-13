#include "../arg_sort.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

int main() {
  std::random_device rd;   // Seed for the random number engine
  std::mt19937 gen(rd());  // Mersenne Twister engine
  std::uniform_int_distribution<> n_dist(1, 10);              // Range: [1, 100]
  std::uniform_int_distribution<> v_dist(-1000000, 1000000);  // Range: [1, 100]

  constexpr size_t num_try = 100;
  for (size_t i{0}; i < num_try; ++i) {
    const size_t n = n_dist(gen);
    std::vector<std::pair<int64_t, int64_t>> vec(n), vec2(n);
    for (size_t j{0}; j < n; ++j) {
      vec[j] = std::make_pair(v_dist(gen), v_dist(gen));
    }
    vec2 = vec;
    util::arg_sort::sort(vec);
    std::sort(vec2.begin(), vec2.end(), [](const auto& l, const auto& r) {
      return std::atan2(l.second, l.first) < std::atan2(r.second, r.first);
    });

    const auto check = [&]() -> bool {
      bool b{false};
      for (size_t k{0}; k < n; ++k) {
        bool b2{true};
        for (size_t l{0}; l < n; ++l) {
          if (vec[l] != vec2[(l + k) % n]) {
            b2 = false;
            break;
          }
        }
        if (b2) {
          b = true;
          break;
        }
      }
      return b;
    };

    if (check()) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "failed" << std::endl;
      std::cout << "vec: ";
      for (auto v : vec) std::cout << "(" << v.first << "," << v.second << "),";
      std::cout << std::endl;
      std::cout << "vec2: ";
      for (auto v : vec2)
        std::cout << "(" << v.first << "," << v.second << "),";
      std::cout << std::endl;
    }
  }

  return 0;
}