#include "util/common.h"

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