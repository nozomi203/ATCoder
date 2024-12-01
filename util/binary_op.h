#include <concepts>
#include <cstdint>
#include <type_traits>

namespace util {

/// @brief get the most significant bit of 64bit integer v
template <std::unsigned_integral Int>
constexpr uint64_t msb(uint64_t v) {
    for (Int shift = 1; shift < sizeof(Int); shift <<= 1) v |= (v >> shift);
    return v ^ (v >> 1);
}

/// @brief get the smallest power of two equal to greater than the non-negative integer v;
template <std::unsigned_integral Int>
constexpr Int binary_ceil(Int v) {
    if (v == 0) return 1;
    --v;
    for (Int shift = 1; shift < sizeof(Int); shift <<= 1) v |= (v >> shift);
    return v + 1;
}
}  // namespace util