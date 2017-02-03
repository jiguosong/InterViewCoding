#ifndef reversebyteofint_H_
#define reversebyteofint_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

class reversebyteofint {
public:
    uint32_t reverseByte_memory_level(uint32_t num);
    uint32_t reverseByte_value_level(uint32_t num);
    uint32_t reverseByte_value_level_2(uint32_t num);
private:
    void swap(int &a, int &b);
};

#endif
