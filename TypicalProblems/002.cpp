#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

void PrintParentheses(s64 bits, s64 bitCnt)
{
    for (s64 shift = bitCnt - 1; shift >= 0; --shift)
    {
        s64 bit = bits & (1 << shift);
        if (bit > 0)
        {
            cout << '(';
        }
        else
        {
            cout << ')';
        }
    }
    cout << endl;
}

bool IsValidParentheses(s64 bits, s64 bitCnt)
{
    s64 det{0};
    for (s64 shift = bitCnt - 1; shift >= 0; --shift)
    {
        s64 bit = bits & (1 << shift);
        if (bit > 0)
        {
            ++det;
        }
        else
        {
            --det;
            if (det < 0)
            {
                return false;
            }
        }
    }

    return det == 0;
}

int main()
{
    s64 N;
    cin >> N;
    s64 bits = (1 << N) - 1;
    for (; bits > 0; --bits)
    {
        if (IsValidParentheses(bits, N))
        {
            PrintParentheses(bits, N);
        }
    }
}