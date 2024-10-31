#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N;
    cin >> N;
    vector<s64> A(N);
    for (s64 n = 0; n < N; ++n)
    {
        cin >> A[n];
    }

    std::sort(A.begin(), A.end());
    for (auto a : A)
    {
        cout << a << " ";
    }
    cout << endl;
}