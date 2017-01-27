/*

*/

#include "reversebyteofint.h"

uint32_t reversebyteofint::reverseByte_memory_level(uint32_t num)
{
    union bytes {
        uint8_t d[4];
        uint32_t n;
    } bytes;

    bytes.n = num;

    uint8_t tmp = 0;
    tmp = bytes.d[0];
    bytes.d[0] = bytes.d[3];
    bytes.d[3] = tmp;

    tmp = bytes.d[1];
    bytes.d[1] = bytes.d[2];
    bytes.d[2] = tmp;

    return bytes.n;
}

uint32_t reversebyteofint::reverseByte_value_level(uint32_t num)
{
    uint32_t res = 0;

    while (num) {
        res |= num & 0xFF;
        num >>= 8;
        if (!num) break;
        res <<= 8;
    }

//    res |= num & 0xFF;
//    res <<= 8;
//    num >>= 8;
//
//    res |= num & 0xFF;
//    res <<= 8;
//    num >>= 8;
//
//    res |= num & 0xFF;
//    res <<= 8;
//    num >>= 8;
//
//    res |= num & 0xFF;

    return res;
}
