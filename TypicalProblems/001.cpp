#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, L, K;
    cin >> N >> L;
    cin >> K;

    vector<s64> A(N);
    for (s64 n = 0; n < N; ++n)
    {
        cin >> A[n];
    }

    // check if yokan can be split into K pieces while keeping minimum length longer than "length"
    const auto canSplit = [&A, L, K](s64 length)
    {
        s64 cnt{0};
        s64 prev{0};
        for (auto a : A)
        {
            if (a - prev >= length)
            {
                ++cnt;
                prev = a;
            }
        }
        if (L - prev >= length)
        {
            ++cnt;
        }
        return cnt >= K + 1;
    };

    s64 l = 0;     // 可能なスコアの最小
    s64 r = L + 1; // 可能なスコアの最大
    while (r - l > 1)
    {
        s64 mid = (l + r) / 2;
        if (canSplit(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << l << endl;
}