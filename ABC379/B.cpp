#include <bits/stdc++.h>

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
    s64 ans = 0;
    s64 cnt = 0;
    for (char c : S)
    {
        if (c == 'O')
        {
            ++cnt;
            if (cnt >= K)
            {
                ++ans;
                cnt = 0;
            }
        }
        else {
            cnt = 0;
        }
    }
    cout << ans << endl;
}