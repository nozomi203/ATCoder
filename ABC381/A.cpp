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
    bool res{ false };
    if (N % 2 == 1)
    {
        s64 n = (N + 1) / 2;
        for (s64 i = 0; i < n - 1; ++i)
        {
            if (S[i] != '1')
            {
                cout << "No" << endl;
                return 0;
            }
        }
        if (S[n - 1] != '/')
        {
            cout << "No" << endl;
            return 0;
        }
        for (s64 i = n; i < N; ++i)
        {
            if (S[i] != '2')
            {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
}