/*
 *
 *   3 ways to determine the endianness
 *
 */

using namespace std;

#include <iostream>
#include <vector>
#include <Print.h>
#include <cstring>

enum Endianness {
    Big,
    Little,
    Unkonwn
};

inline Endianness DetermineEndianness(void)
{
    std::uint16_t x = 0x0102;
    auto byte = reinterpret_cast<char *>(&x);
    switch (*byte) {
        case 1:
            return Endianness::Big;
        case 2:
            return Endianness::Little;
        default:
            return Endianness::Unkonwn;
    }
}


union bytes {
    uint8_t byte[4];
    uint32_t m;
};

int main()
{
    unsigned int i = 1;
    char *p = (char *) &i;

    if (p[0] == 0) cout << "big endian" << endl;
    if (p[0] == 1) cout << "little endian" << endl;

    Endianness x = DetermineEndianness();
    if (x == Endianness::Little) cout << "little endian" << endl;
    else if (x == Endianness::Big) cout << "big endian" << endl;

    if (__BYTE_ORDER == __LITTLE_ENDIAN) { cout << "little endian" << endl; }
    else if (__BYTE_ORDER == __BIG_ENDIAN) { cout << "big endian" << endl; }



    vector <uint32_t> mem = {0x1111AAAA, 0x5151A2A2};
    vector <uint8_t> bytesres;

    for (auto e:mem) {
        bytes x;
        x.m = e;
        for (int j = 0; j < 4; ++j) {
            bytesres.push_back(x.byte[i]);
        }
        break;
    }

    cout << pprint::to_string(bytesres) << endl;

}


