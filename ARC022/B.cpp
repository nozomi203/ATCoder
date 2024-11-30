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
    vector<s64> A(N);
    for (s64 i = 0; i < N; ++i) cin >> A[i];
    // lastIdx[i] = largest idx of taste i.
    // -1 if i has not been appeared.
    vector<s64> lastIdx(1000000, -1);

    s64 r{0};
    s64 ans{0};
    for (s64 l = 0; l < N; ++l) {
        while (r == l || (r < N && lastIdx[A[r]] < l)) {
            lastIdx[A[r]] = r;
            ++r;
        }

        ans = max(ans, r - l);
    }

    cout << ans << endl;
}