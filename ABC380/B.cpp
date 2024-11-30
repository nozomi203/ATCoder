#include <bits/stdc++.h>
#include <atcoder/all>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    string S;
    cin >> S;
    s64 cnt{ 0 };
    for (char c : S)
    {
        if (c == '|')
        {
            if (cnt != 0)
            {
                cout << cnt << " ";
            }
            cnt = 0;
        }
        else {
            ++cnt;
        }
    }
    cout << endl;
}