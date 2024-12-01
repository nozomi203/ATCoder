#include "util/binary_op.h"

#include <cassert>
#include <iostream>

#include "util/test.h"

int main() {
    TEST(util::binary_ceil<uint32_t>(9), 16);
}