#ifndef myAllocator_H
#define myAllocator_H

/* block prefix & suffix */
typedef struct BlockPrefix_s {
  struct BlockSuffix_s *suffix;
  int allocated;
} BlockPrefix_t;

typedef struct BlockSuffix_s {
  struct BlockPrefix_s *prefix;
} BlockSuffix_t;

BlockPrefix_t *lastAllocated; /* prefix for last allocated block */

void arenaCheck(void);
void *firstFitAllocRegion(size_t s);
void *nextFitAllocRegion(size_t s);
void *bestFitAllocRegion(size_t s);
void freeRegion(void *r);
void *resizeRegion(void *r, size_t newSize);
size_t computeUsableSpace(BlockPrefix_t *p);
BlockPrefix_t *regionToPrefix(void *r);
BlockPrefix_t *makeFreeBlock(void *addr, size_t size);
BlockPrefix_t *regionToPrefix(void *r);
#endif // myAllocator_H
