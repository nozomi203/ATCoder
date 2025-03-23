#include "../radix_heap.h"

#include <iostream>

#include "../test.h"

int main() {
  util::radix_heap32 rh;
  rh.push(3);
  rh.push(8);
  rh.push(5);
  TEST(rh.pop(), 3);
  rh.push(4);
  TEST(rh.pop(), 4);
  TEST(rh.pop(), 5);
}