#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, X;
    cin >> N >> X;
    vector<s64> A(N);
    for (s64 n = 0; n < N; ++n)
    {
        cin >> A[n];
    }
    sort(A.begin(), A.end());
    const auto XItr = std::lower_bound(A.begin(), A.end(), X);
    cout << (XItr != A.end() && *XItr == X ? "Yes" : "No") << endl;
}