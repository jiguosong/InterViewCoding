/*

 The easiest way to do it is to keep a linked list of free block. In malloc, if the list is not empty,
 you search for a block large enough to satisfy the request and return it. If the list is empty or
 if no such block can be found, you call sbrk to allocate some memory from the operating system.
 in free, you simply add the memory chunk to the list of free block. As bonus, you can try to merge
 contiguous freed block, and you can change the policy for choosing the block to return (first fit,
 best fit, ...). You can also choose to split the block if it is larger than the request.

 http://stackoverflow.com/questions/3839922/aligned-malloc-in-gcc
 http://stackoverflow.com/questions/5422061/malloc-implementation#5422447

*/

#include <unistd.h>
#include "simplemalloc.h"

void *simplemalloc::mymalloc(size_t size)
{
    if (!size) return nullptr;

    if ((alignment != 0) && (alignment & (alignment - 1)) != 0) return nullptr;

    // return aligned_alloc(32, 1024);
    //void *p;
    //posix_memalign(&p, 16, 1024);

    size = (size + sizeof(freeblock) + alignment - 1);
    freeblock *block = freeblock_listhead.next;
    freeblock **head = &(freeblock_listhead.next);

    while (block != 0) {
        if (block->size >= size) {
            printf("found one\n");
            *head = block->next;
            return ((char *) block) + sizeof(freeblock);
        }

        printf("not found one\n");
        printf("block->size %d\n", block->size);
        head = &(block->next);
        block = block->next;
    }

    block = (freeblock *) sbrk(size);
    block->size = size;

    void *p = (void **) (((size_t) (block) + sizeof(freeblock) + alignment - 1) & ~(alignment - 1));
    printf("in alloc %p\n", (char *) p);
    freeblock *test = (freeblock *) ((char *) p - sizeof(freeblock));
    printf("in alloc test->size %d\n", test->size);
    return p;
}

void simplemalloc::myfree(void *ptr)
{
    if (ptr == nullptr) return;
    printf("in free %p\n", (char *) ptr);
    freeblock *block = (freeblock *) ((char *) ptr - sizeof(freeblock));
    printf("in free block->size %d\n", block->size);
    block->next = freeblock_listhead.next;
    freeblock_listhead.next = block;
}



