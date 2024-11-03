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
    unordered_map<s64, s64> latestIdx;
    vector<s64> B(N + 1);
    for (s64 n = 1; n <= N; ++n)
    {
        s64 An;
        cin >> An;
        auto itr = latestIdx.find(An);
        B[n] = itr != latestIdx.end() ? itr->second : -1;
        latestIdx[An] = n;
    }

    for (s64 n = 1; n <= N; ++n)
    {
        cout << B[n] << " ";
    }
    cout << endl;
}