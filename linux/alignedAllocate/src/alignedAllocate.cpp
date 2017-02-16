#include <cstdlib>
#include <unistd.h>
#include "alignedAllocate.h"

/*
For a more generic memory allocation function, the caller doesn't want to have to keep track of two
pointers (one to use and one to free). So you store a pointer to the 'real' buffer below the aligned buffer.

Steps:
1. We will use malloc routine provided by C to implement the functionality.
   Allocate memory of size (bytes required + alignment - 1 + sizeof(void*)) using malloc.
   alignment: malloc can give us any address and we need to find a multiple of alignment.
   (Therefore, at maximum multiple of alignment, we will be alignment-1 bytes away from any location.)
   sizeof(size_t): We are returning a modified memory pointer to user, which is different
   from the one that would be returned by malloc. We also need to extra space to store the
   address given by malloc, so that we can free memory in aligned_free by calling free
   routine provided by C.

2. If it returns NULL, then aligned_malloc will fail and we return NULL.

3. Else, find the aligned memory address which is a multiple of alignment (call this p2).

4. Store the address returned by malloc (e.g., p1 is just size_t bytes ahead of p2),
   which will be required by aligned_free.

5. Return p2.

 https://sites.google.com/site/ruslancray/lab/bookshelf/interview/ci/low-level/write-an-aligned-malloc-free-function
 http://stackoverflow.com/questions/600293/how-to-check-if-a-number-is-a-power-of-2#600306

 // Allocate raw memory for a Foo object.  Example of using posix_memalign
    void *mem;
    size_t alignment = 0x1000;
    size_t size = ?;
    posix_memalign(&mem, alignment, size);
    // Call the constructor on the allocated memory.
    Foo *foo = new (mem) Foo(...);

    // Now you have a useable object.
    foo->some_method();

    // Call destructor without freeing object memory.
    foo->~Foo();
    // Free raw memory.
    free(foo);

*/

void *alignedAllocate_test::alignedAllocate(uint32_t sizeInBytes, uint32_t alignment)
{
    void *p1;  // original block
    void **p2; // aligned block
    if (alignment != 0 && (alignment & (alignment - 1)) != 0) return nullptr;   // must be power 2

    int offset = sizeof(void *) + alignment - 1;
    if ((p1 = (void **) malloc(sizeInBytes + offset)) == nullptr) return nullptr;
    p2 = (void **) (((size_t) (p1) + offset) & ~(alignment - 1));
    p2[-1] = p1;
    return p2;

}

void alignedAllocate_test::alignned_free(void *p)
{
    free(((void **) p)[-1]);
}


typedef struct free_block {
    size_t size;
    struct free_block *next;
} free_block;

static free_block free_block_list_head = {0, 0};

// static const size_t overhead = sizeof(size_t);

// static const size_t align_to = 16;


void *alignedAllocate_test::alignedAllocate2(uint32_t sizeInBytes, uint32_t align_to)
{
    sizeInBytes = (sizeInBytes + sizeof(free_block) + (align_to - 1)) & ~(align_to - 1);
    free_block *block = free_block_list_head.next;
    free_block **head = &(free_block_list_head.next);
    while (block != 0) {
        if (block->size >= sizeInBytes) {
            *head = block->next;
            return ((char *) block) + sizeof(free_block);
        }
        head = &(block->next);
        block = block->next;
    }

    block = (free_block *) sbrk(sizeInBytes);
    block->size = sizeInBytes;

    return ((char *) block) + sizeof(free_block);
}

void alignedAllocate_test::alignned_free2(void *ptr)
{
    free_block *block = (free_block *) (((char *) ptr) - sizeof(free_block));
    block->next = free_block_list_head.next;
    free_block_list_head.next = block;
}




