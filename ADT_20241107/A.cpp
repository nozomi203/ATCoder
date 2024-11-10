#include <bits/stdc++.h>
using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 A, B, D;
    cin >> A >> B >> D;
    while (A <= B)
    {
        cout << A << " ";
        A += D;
    }
    cout << endl;
}