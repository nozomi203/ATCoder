#line 1 "C:\\Users\\takan\\Documents\\Program\\ATCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "main.cpp"

int main() {
    s64 X;
    cin >> X;
    s64 ans{0};
    for(int i = 1; i <= 9; ++i)
    {
        for(int j = 1; j <= 9; ++j)
        {
            auto prod = i * j;
            if(prod != X)
            {
                ans += prod;
            }
        }
    }
    cout << ans << endl;
}
