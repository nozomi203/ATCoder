#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N;
    string S;
    cin >> N >> S;
    s64 state{ 0 }, cnt1{ 0 }, cnt2{ 0 };
    s64 ans{ 0 };
    s64 one = 1;
    for (s64 i = 0; i < N; ++i)
    {
        char c = S[i];
        switch (state)
        {
        case 0: // 候補のいない状態
            switch (c)
            {
            case '1':
                state = 1;
                cnt1 = 1;
                break;
            case '/':
                ans = std::max(ans, one);
                break;
            default:
                break;
            }
            break;
        case 1: // /を探す
            switch (c)
            {
            case '1':
                ++cnt1;
                break;
            case '/':
                ans = std::max(ans, one);
                state = 2;
                break;
            default:
                state = 0;
                break;
            }
            break;
        case 2: // 2を探す
            switch (c)
            {
            case '2':
                if (++cnt2 > cnt1)
                {
                    cnt2 = 0;
                    state = 0;
                    break;
                }
                ans = std::max(ans, cnt2 * 2 + 1);
                break;
            case '1':
                cnt2 = 0;
                state = 1;
                cnt1 = 1;
                break;
            default:
                cnt2 = 0;
                state = 0;
                break;
            }
            break;
        }
    }

    cout << ans << endl;
}