#pragma once
#include <concepts>
#include <cstdio>

namespace util {

template <typename T>
inline void cin(T& t) {}

template <std::unsigned_integral T>
inline void cin(T& t) {
}
}  // namespace util