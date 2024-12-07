#define TEST(op, expected)                                \
  if (op == expected) {                                   \
    std::cout << "(" << #op << " == " << #expected        \
              << ") \033[32m[passed]\033[m" << std::endl; \
  } else {                                                \
    std::cout << "(" << #op << " == " << #expected        \
              << ") \033[31m[failed]\033[m" << std::endl; \
  }