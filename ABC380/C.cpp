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
    string S;
    cin >> S;

    vector<s64> starts(K + 1, S.size());
    vector<s64> ends(K + 1, S.size());
    s64 group{ 0 };
    bool inside{ false };
    for (u64 idx = 0; idx < S.size(); ++idx)
    {
        if (S[idx] == '1')
        {
            if (!inside)
            {
                inside = true;
                ++group;
                starts[group] = idx;
            }
        }
        else
        {
            if (inside)
            {
                inside = false;
                ends[group] = idx;
                if (group == K)
                {
                    break;
                }
            }
        }
    }

    cout << S.substr(0, ends[K - 1]);
    cout << S.substr(starts[K], ends[K] - starts[K]);
    cout << S.substr(ends[K - 1], starts[K] - ends[K - 1]);
    cout << S.substr(ends[K]) << endl;
}