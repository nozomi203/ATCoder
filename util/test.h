#include <iostream>

#define TEST(op, expected)                                                 \
  {                                                                        \
    auto ret = op;                                                         \
    std::cout << "(" << #op << " == " << #expected << ") return: " << ret; \
    if (ret == expected) {                                                 \
      std::cout << " \033[32m[passed]\033[m" << std::endl;                 \
    } else {                                                               \
      std::cout << " \033[31m[failed]\033[m" << std::endl;                 \
    }                                                                      \
  }