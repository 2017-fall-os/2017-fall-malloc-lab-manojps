/* This test program for best-fit allocator allocates seven regions, 
 * then deallocates three "even numbered" regions, then requests to 
 * allocate memory such that the best-fit would be the second even 
 * numbered region.
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
  void *p1, *p2, *p3, *p4, *p5, *p6, *p7;
  arenaCheck();

  /* Allocate five regions to test best-fit */
  p1 = bestFitAllocRegion(200);
  p2 = bestFitAllocRegion(700);
  p3 = bestFitAllocRegion(400);
  p4 = bestFitAllocRegion(600);
  p5 = bestFitAllocRegion(800);
  p6 = bestFitAllocRegion(900);
  p7 = bestFitAllocRegion(1000);
  arenaCheck();
  
  /* free some blocks */
  freeRegion(p2);
  freeRegion(p4);
  freeRegion(p6);
  arenaCheck();
  bestFitAllocRegion(500); /* allocating region using best-fit */
  arenaCheck();
  
  freeRegion(p1);
  freeRegion(p2);
  freeRegion(p3);
  freeRegion(p4);
  freeRegion(p5);
 
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
