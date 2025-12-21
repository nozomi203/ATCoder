#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

namespace util {

template <typename T>
inline void cin(T& t) {
  std::cin >> t;
}

template <typename Tuple, std::size_t... I>
inline void cin_tuple_impl(Tuple& t, std::index_sequence<I...>) {
  ((util::cin(std::get<I>(t))), ...);
}

template <typename... Ts>
inline void cin(tuple<Ts...>& t) {
  cin_tuple_impl(t, index_sequence_for<Ts...>{});
}

template <typename First, typename Second>
inline void cin(pair<First, Second>& p) {
  util::cin(p.first);
  util::cin(p.second);
}

template <typename T>
inline void cin(vector<T>& v) {
  for (auto& e : v) {
    util::cin(e);
  }
}

template <typename Iterator>
inline void cin(Iterator first, Iterator last) {
  for (auto it = first; it != last; ++it) {
    util::cin(*it);
  }
}

template <typename... Ts>
inline void cin(Ts&... ts) {
  ((util::cin(ts)), ...);
}

template <typename T>
inline void sort(vector<T>& v) {
  std::sort(v.begin(), v.end());
}

template <typename T, typename Compare>
inline void sort(vector<T>& v, Compare comp) {
  std::sort(v.begin(), v.end(), std::forward(comp));
}

}  // namespace util
#line 2 "main.cpp"

int main() {
  s64 n, m;
  cin >> n >> m;
  vector<string> ss(n);
  util::cin(ss);
  vector<s64> cnts(n);
  for (s64 i = 0; i < m; ++i) {
    s64 cnt0 = 0;
    for (s64 j = 0; j < n; ++j) {
      if (ss[j][i] == '0') ++cnt0;
    }
    const char c = (cnt0 > 0 && cnt0 < n - cnt0) ? '0' : '1';
    for (s64 j = 0; j < n; ++j)
      if (ss[j][i] == c) ++cnts[j];
  }

  vector<s64> answers;
  const s64 mcnt = *max_element(cnts.begin(), cnts.end());
  for (s64 i = 0; i < n; ++i) {
    if (cnts[i] == mcnt) answers.push_back(i + 1);
  }
  for (s64 i = 0; i < answers.size(); ++i) {
    cout << answers[i];
    if (i < answers.size() - 1) cout << " ";
  }
  cout << endl;
}
