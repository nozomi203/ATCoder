#include "util/segment_tree.h"

#include <cassert>
#include <cstdint>
#include <iostream>

#include "util/test.h"

int main() {
    util::segment_tree<uint32_t> st(4);
    TEST(st.get_buffer_size(), 7);
}