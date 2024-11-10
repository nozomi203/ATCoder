#include <bits/stdc++.h>
using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    string S;
    cin >> S;
    char prev = 0;
    bool yes{ true };
    for (char c : S)
    {
        if (prev > c)
        {
            yes = false;
            break;
        }
        prev = c;
    }
    cout << (yes ? "Yes" : "No") << endl;
}