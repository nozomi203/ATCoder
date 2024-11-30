#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N, K;
    cin >> N >> K;
    vector<s64> S(N);
    bool hasZero{false};
    for (s64 i = 0; i < N; ++i)
    {
        cin >> S[i];
        if (S[i] == 0)
            hasZero = true;
    }

    if (hasZero)
    {
        cout << N << endl;
        return 0;
    }

    s64 ans{0};
    s64 mul{1};
    s64 r{0};
    for (s64 l = 0; l < N; ++l)
    {
        while (r < N && mul * S[r] <= K)
        {
            mul *= S[r];
            ++r;
        }

        ans = std::max(ans, r - l);

        if (r == l)
        {
            ++r;
        }
        else
        {
            mul /= S[l];
        }
    }

    cout << ans << endl;
}