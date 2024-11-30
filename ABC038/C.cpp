#include <bits/stdc++.h>

#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main() {
    s64 N;
    cin >> N;
    vector<s64> a(N);
    for (s64 i = 0; i < N; ++i) cin >> a[i];

    s64 r{0};
    s64 ans{0};
    for (s64 l = 0; l < N; ++l) {
        while (r == l || (r < N && a[r] > a[r - 1])) {
            ++r;
        }

        ans += (r - l);

        if (r == l) {
            ++r;
        }
    }
    cout << ans << endl;
}