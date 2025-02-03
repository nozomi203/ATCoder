#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
  u32 N, K;
  cin >> N >> K;
  vector<u64> A(N), B(N), C(N);
  for (u32 i = 0; i < N; ++i) cin >> A[i];
  for (u32 i = 0; i < N; ++i) cin >> B[i];
  for (u32 i = 0; i < N; ++i) cin >> C[i];
  sort(A.begin(), A.end(), greater<u32>());
  sort(B.begin(), B.end(), greater<u32>());
  sort(C.begin(), C.end(), greater<u32>());

  const auto get_value = [&](u32 idx_a, u32 idx_b, u32 idx_c) -> u64 {
    u64 a = A[idx_a];
    u64 b = B[idx_b];
    u64 c = C[idx_c];
    return a * b + b * c + c * a;
  };

  using value = tuple<u64, u32, u32, u32>;
  class compare {
   public:
    bool operator()(const value& l, const value& r) {
      return get<0>(l) < get<0>(r);
    }
  };
  set<tuple<u32, u32, u32>> checked;
  priority_queue<value, vector<value>, compare> queue;
  queue.push({get_value(0, 0, 0), 0, 0, 0});
  checked.emplace(make_tuple(0, 0, 0));
  u64 ans{0};
  for (u32 k = 0; k < K; ++k) {
    const auto val = queue.top();
    queue.pop();
    ans = get<0>(val);
    if (get<1>(val) + 1 < A.size() &&
        checked.count(make_tuple(get<1>(val) + 1, get<2>(val), get<3>(val))) ==
            0) {
      queue.push({get_value(get<1>(val) + 1, get<2>(val), get<3>(val)),
                  get<1>(val) + 1, get<2>(val), get<3>(val)});
      checked.emplace(make_tuple(get<1>(val) + 1, get<2>(val), get<3>(val)));
    }
    if (get<2>(val) + 1 < B.size() &&
        checked.count(make_tuple(get<1>(val), get<2>(val) + 1, get<3>(val))) ==
            0) {
      queue.push({get_value(get<1>(val), get<2>(val) + 1, get<3>(val)),
                  get<1>(val), get<2>(val) + 1, get<3>(val)});
      checked.emplace(make_tuple(get<1>(val), get<2>(val) + 1, get<3>(val)));
    }
    if (get<3>(val) + 1 < C.size() &&
        checked.count(make_tuple(get<1>(val), get<2>(val), get<3>(val) + 1)) ==
            0) {
      queue.push({get_value(get<1>(val), get<2>(val), get<3>(val) + 1),
                  get<1>(val), get<2>(val), get<3>(val) + 1});
      checked.emplace(make_tuple(get<1>(val), get<2>(val), get<3>(val) + 1));
    }
  }
  cout << ans << endl;
}
