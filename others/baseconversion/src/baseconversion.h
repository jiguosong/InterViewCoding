#ifndef baseconversion_H_
#define baseconversion_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

class baseconversion {
public:
    unsigned int convert_10base_to_nbase(int nums_10base, int n);
    unsigned int convert_nbase_to_10base(int nums_nbase, int n);
    unsigned int convert_nbase_to_mbase(int nums_nbase, int n, int m);
private:

};

#endif
