#include <bits/stdc++.h>
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
    bool in{ false };
    for (char c : S)
    {
        switch (c)
        {
        case '|':
            in = !in;
            break;
        case '*':
            cout << (in ? "in" : "out") << endl;
            break;
        default:
            break;
        }
    }
}