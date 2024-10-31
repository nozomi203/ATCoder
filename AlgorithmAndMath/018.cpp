#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;

int main()
{
    s64 N;
    cin >> N;

    array<s64, 5> productCountPerPrice{};
    for (s64 n = 0; n < N; ++n)
    {
        s64 A;
        cin >> A;
        s64 price = A / 100;
        productCountPerPrice[price]++;
    }

    s64 count = productCountPerPrice[1] * productCountPerPrice[4] + productCountPerPrice[2] * productCountPerPrice[3];
    cout << count << endl;
}