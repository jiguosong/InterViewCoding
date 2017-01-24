/*

*/

#include "powerxn.h"

float powerxn::Power(float x, int n)
{
    if (n == 0) return 1;

    int y = n / 2;
    float tmp = Power(x, y);

    if (n % 2 == 0) {
        return tmp * tmp;
    } else {
        if (n > 0) return x * tmp * tmp;
        else return tmp * tmp / x;
    }
}

