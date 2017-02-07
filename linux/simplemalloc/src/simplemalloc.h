#ifndef simplemalloc_H_
#define simplemalloc_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

class simplemalloc {
public:
    void *mymalloc(size_t size);

    void myfree(void *ptr);

    simplemalloc(uint32_t align_size)
    {
        freeblock_listhead.size = 0;
        freeblock_listhead.next = nullptr;
        alignment = align_size;
    }

private:
    struct freeblock {
        size_t size;
        freeblock *next;

        freeblock() : size(0), next(nullptr)
        { };
    };

    freeblock freeblock_listhead;
    uint32_t alignment;
};

#endif
