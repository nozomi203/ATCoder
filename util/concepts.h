#include <concepts>

namespace util::concepts {

template <class T, class TRet, class... TArgs>
concept Function = requires(T func, TArgs... args) {
  { func(args...) } -> std::convertible_to<TRet>;
};

}  // namespace util