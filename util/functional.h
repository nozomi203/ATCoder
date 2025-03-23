#pragma once

namespace util {
template <class T>
struct minimum {
  static size_t operator()(size_t l, size_t r) { return std::min(l, r); }
};
}  // namespace util