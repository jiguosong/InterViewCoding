/*
 http://www.cppblog.com/woaidongmao/archive/2009/08/04/92147.html
 http://blog.csdn.net/hemmingway/article/details/8652600

 convert byte to word, word to byte,....

 http://stackoverflow.com/questions/673240/how-do-i-print-an-unsigned-char-as-hex-in-c-using-ostream#673389
 */

#include <iostream>
#include <Print.h>
#include <bitset>

using namespace std;

#define MAKEWORD(a, b)  ((uint16_t)(((char)(((uint32_t)(a)) & 0xff)) | ((uint16_t)((char)(((uint32_t)(b)) & 0xff))) << 8))
#define MAKELONG(a, b)  ((long)(((uint16_t)(((uint32_t)(a)) & 0xffff)) | ((uint32_t)((uint16_t)(((uint32_t)(b)) & 0xffff))) << 16))
#define LOWORD(l)       ((uint16_t)(((uint32_t)(l)) & 0xffff))
#define HIWORD(l)       ((uint16_t)((((uint32_t)(l)) >> 16) & 0xffff))
#define LOBYTE(w)       ((char)(((uint32_t)(w)) & 0xff))
#define HIBYTE(w)       ((char)((((uint32_t)(w)) >> 8) & 0xff))


// ==========================================================
//   Big Endian / Small Endian utility functions
// ==========================================================
bool IsSmallEndian()
{
    uint32_t wd = 0x22;
    if (*((char *) &wd) == 0x22)  // Small Endian
        return true;
    else
        return false;
}

void SwapShort(uint16_t *sp)
{
    char *cp = (char *) sp, t = cp[0];
    cp[0] = cp[1];
    cp[1] = t;
}

void SwapLong(uint32_t *lp)
{
    char *cp = (char *) lp, t = cp[0];
    cp[0] = cp[3];
    cp[3] = t;
    t = cp[1];
    cp[1] = cp[2];
    cp[2] = t;
}

// int 2 byte
char *Int2Byte(int nVal)
{
    char *pByte = new char[4];
    for (int i = 0; i < 4; i++) {
        pByte[i] = (char) (nVal >> 8 * (3 - i) & 0xff);
    }
    return pByte;
}

// byte 2 int
int Byte2Int(char *pb)
{
    // assume the length of pb is 4
    int nValue = 0;
    for (int i = 0; i < 4; i++) {
        nValue += (pb[i] & 0xFF) << (8 * (3 - i));
    }
    return nValue;
}

int main(int argc, char *argv[])
{
    //this machine is little endian

    //////////////////////////////////////////////////////////////////////////
    unsigned int num = 0x12345678;
    char *byte = Int2Byte(num);
    cout << hex << +byte[0] << endl;
    cout << hex << +byte[1] << endl;
    cout << hex << +byte[2] << endl;
    cout << hex << +byte[3] << endl;

    int nVal = Byte2Int(byte);
    cout << hex << +nVal << endl;

    //////////////////////////////////////////////////////////////////////////
    // little endian: 0xefcdab89, big endian:0x89abcdef
    uint16_t wLow, wHigh;
    uint32_t dwData;

    // DWORD is decomposed into char array
    uint32_t dwVal = 0xefcdab89;
    uint16_t lo = LOWORD(dwVal), hi = HIWORD(dwVal);
    cout << hex << +lo << endl;
    cout << hex << +hi << endl;

    //from byte array to form the uint32_t
    char b[4] = {0x89, 0xab, 0xcd, 0xef};
    wLow = MAKEWORD(b[0], b[1]);
    wHigh = MAKEWORD(b[2], b[3]);
    dwData = MAKELONG(wLow, wHigh);
    printf("wLow=0x%xh,wHigh=0x%xh,dwData=0x%xh\n", wLow, wHigh, dwData);

    return 0;
}