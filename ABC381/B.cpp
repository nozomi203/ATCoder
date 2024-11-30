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
    if (S.size() % 2 != 0)
    {
        cout << "No" << endl;
        return 0;
    }
    vector<bool> appear(26, false);
    for (s64 i = 0; i < S.size() / 2; ++i)
    {
        char c = S[2 * i];
        if (c != S[2 * i + 1])
        {
            cout << "No" << endl;
            return 0;
        }
        if (appear[c - 'a'])
        {
            cout << "No" << endl;
            return 0;
        }
        appear[c - 'a'] = true;
    }
    cout << "Yes" << endl;
}