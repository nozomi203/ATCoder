#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
    s64 N, M;
    cin >> N >> M;
    vector<s64> A(N + 1), B(M + 1);
    for (s64 i = 1; i <= N; ++i) cin >> A[i];
    for (s64 i = 1; i <= M; ++i) cin >> B[i];

    std::vector<std::pair<s64, s64>> v;
    s64 min{std::numeric_limits<s64>::max()};
    for (s64 i = 1; i <= N; ++i) {
        if (A[i] < min) {
            min = A[i];
            v.emplace_back(min, i);
        }
    }
    std::reverse(v.begin(), v.end());

    for (s64 i = 1; i <= M; ++i) {
        auto b = B[i];
        auto itr = std::upper_bound(v.begin(), v.end(), b, [](auto b, auto& elem) {
            return b < elem.first;
        });

        cout << (itr == v.begin() ? -1 : std::prev(itr)->second) << endl;
    }
}
