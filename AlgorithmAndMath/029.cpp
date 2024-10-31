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

    vector<s64> stepPatterns(N + 1);
    stepPatterns[0] = 1;
    stepPatterns[1] = 1;
    for (s64 n = 2; n <= N; ++n)
    {
        stepPatterns[n] = stepPatterns[n - 2] + stepPatterns[n - 1];
    }
    cout << stepPatterns[N] << endl;
}