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
    cin >> N;
    string S;
    cin >> S;
    s64 A = 0;
    for (s64 i = 1; i <= N; ++i)
    {
        A += (S[i - 1] - '0') * i;
    }
    vector<s64> digits;
    s64 rem = 0;
    for (s64 n = N; n > 0; --n)
    {
        rem += A;
        s64 digit = rem % 10;
        digits.push_back(digit);
        rem -= digit;
        rem /= 10;
        A -= (S[n - 1] - '0') * n;

    }
    // 余剰
    while (rem > 0)
    {
        s64 digit = rem % 10;
        digits.push_back(digit);
        rem -= digit;
        rem /= 10;
    }
    for (auto ritr = digits.rbegin(); ritr != digits.rend(); ++ritr)
    {
        cout << *ritr;
    }
    cout << endl;
}