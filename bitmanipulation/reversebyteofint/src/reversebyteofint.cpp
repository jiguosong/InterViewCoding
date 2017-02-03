/*
    Convert Little Endian to Big Endian
    http://stackoverflow.com/questions/3745637/problems-with-byte-reversing-an-integer
*/

#include "reversebyteofint.h"

uint32_t reversebyteofint::reverseByte_memory_level(uint32_t num)
{
    union bytes {
        uint8_t d[4];
        uint32_t n;
    } bytes;

    bytes.n = num;

    bytes.d[0] = bytes.d[0] ^ bytes.d[3];
    bytes.d[3] = bytes.d[0] ^ bytes.d[3];
    bytes.d[0] = bytes.d[0] ^ bytes.d[3];

    bytes.d[1] = bytes.d[1] ^ bytes.d[2];
    bytes.d[2] = bytes.d[1] ^ bytes.d[2];
    bytes.d[1] = bytes.d[1] ^ bytes.d[2];

//    uint8_t tmp = 0;
//    tmp = bytes.d[0];
//    bytes.d[0] = bytes.d[3];
//    bytes.d[3] = tmp;
//
//    tmp = bytes.d[1];
//    bytes.d[1] = bytes.d[2];
//    bytes.d[2] = tmp;

    return bytes.n;
}

uint32_t reversebyteofint::reverseByte_value_level_2(uint32_t num)
{
    uint32_t res = 0;
    uint32_t b0, b1, b2, b3;

    b0 = (num & 0x000000ff) << 24u;
    b1 = (num & 0x0000ff00) << 8u;
    b2 = (num & 0x00ff0000) >> 8u;
    b3 = (num & 0xff000000) >> 24u;
    res = b0 | b1 | b2 | b3;

    return res;
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

    return res;
}


