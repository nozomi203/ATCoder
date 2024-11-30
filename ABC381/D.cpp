#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s32 N;
    cin >> N;
    vector<s32> A(N);
    for (s32 i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    s32 ans{ 0 };
    for (s32 offset = 0; offset <= 1; ++offset) {
        map<s32, s32> lastAppearIdx;
        s32 len{ 0 };
        for (s32 i = 0; 2 * i + offset + 1 < N; ++i)
        {
            s64 idx1 = 2 * i + offset;
            s64 idx2 = idx1 + 1;
            if (A[idx1] != A[idx2])
            {
                lastAppearIdx.clear();
                ans = max(ans, len);
                len = 0;
                continue;
            }
            const s32 val = A[idx1];
            if (auto itr = lastAppearIdx.find(val); itr != lastAppearIdx.end())
            {
                ans = std::max(ans, len);
                len = idx1 - itr->second;
            }
            else
            {
                len += 2;
            }
            lastAppearIdx[val] = idx1;
        }
        ans = max(ans, len);
    }
    cout << ans << endl;
}