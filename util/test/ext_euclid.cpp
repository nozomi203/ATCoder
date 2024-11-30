#include "../ext_euclid.h"

int main()
{
    int64_t a, b, c, x, y;
    a = 90;
    b = -37;
    c = 1;
    if (ext_euclid(a, b, c, x, y))
    {
        std::cout << "x:" << x << "y:" << y << std::endl;
    }
}