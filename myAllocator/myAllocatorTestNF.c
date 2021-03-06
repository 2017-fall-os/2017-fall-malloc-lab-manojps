/* This test program for next-fit allocator allocates three regions, 
 * deallocates the middle region by changing prefix->allocate to 0, 
 * sets the last allocated prefix to the middle region, and then 
 * allocates another region in the newly allocated region.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#include "myAllocator.h"

double diffTimeval(struct timeval *t1, struct timeval *t2) {
  double d = (t1->tv_sec - t2->tv_sec) + (1.0e-6 * (t1->tv_usec - t2->tv_usec));
  return d;
}

void getutime(struct timeval *t) {
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  *t = usage.ru_utime;
}

int main() {
  void *p1, *p2, *p3;
  arenaCheck();
 /* p1 = nextFitAllocRegion(254);
  arenaCheck();
  p2 = nextFitAllocRegion(25400);
  arenaCheck();
  p3 = nextFitAllocRegion(254);
  printf("%p %p %p\n", p1, p2, p3);
  arenaCheck();
  freeRegion(p2);
  arenaCheck();
  freeRegion(p3);
  arenaCheck();
  freeRegion(p1);
  arenaCheck(); */

  /* Allocate three regions to test next-fit */
  p1 = nextFitAllocRegion(200);
  p2 = nextFitAllocRegion(500);
  p3 = nextFitAllocRegion(400);
  arenaCheck();
  lastAllocated = regionToPrefix(p2); /* setting the prefix for the p2 region as the last allocated region's prefix */
  lastAllocated->allocated = 0; /* setting region p2 as unallocated */
  arenaCheck();
  p2 = nextFitAllocRegion(300); /* allocating region using next-fit */
  arenaCheck();
  freeRegion(p1);
  freeRegion(p2);
  freeRegion(p3);
  arenaCheck();
  { /* measure time for 10000 mallocs */
    struct timeval t1, t2;
    int i;
    getutime(&t1);
    for(i = 0; i < 10000; i++)
      if (firstFitAllocRegion(4) == 0)
        break;
    getutime(&t2);
    printf("%d firstFitAllocRegion(4) required %f seconds\n", i, diffTimeval(&t2, &t1));
  }
  return 0;
}
