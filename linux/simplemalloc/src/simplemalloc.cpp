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

    size = (size + sizeof(freeblock) + alignment - 1) & (alignment - 1);
    freeblock *block = freeblock_listhead.next;
    freeblock **head = &(freeblock_listhead.next);

    while (block) {
        if (block->size >= size) {
            *head = block->next;
            return ((char *) block) + sizeof(freeblock);
        }

        head = &(block->next);
        block = block->next;
    }

    block = (freeblock *) sbrk(size);
    block->size = size;

    return ((char *) block) + sizeof(freeblock);
}

void simplemalloc::myfree(void *ptr)
{
    if (ptr == nullptr) return;
    freeblock *block = (freeblock *) ((char *) ptr - sizeof(freeblock));
    block->next = freeblock_listhead.next;
    freeblock_listhead.next = block;
}



