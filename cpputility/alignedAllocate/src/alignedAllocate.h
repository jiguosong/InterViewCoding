#ifndef ALIGNEDALLOCATE_H_
#define ALIGNEDALLOCATE_H_

//#include <cstdint>

#include <cstdint>

class alignedAllocate_test {
public:
    void *alignedAllocate(uint32_t sizeInBytes, uint32_t alignment);

    void alignned_free(void *p);
};


#endif /* ALIGNEDALLOCATE_H_ */
