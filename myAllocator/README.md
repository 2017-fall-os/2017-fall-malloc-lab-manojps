I have implemented the resizeRegion() function and next-fit and best-fit allocators by extending the source code provided by Dr. Freudenthal. My allocators and test cases can be accessed in the `myAllocator` directory.

The improved resizeRegion() function and next-fit and best-fit allocators are defined inside `myAllocator.c` file. I have also modified `myAllocator.h` header file to implement next-fit allocator and to implement the test cases for resizeRegion() funtion, next-fit allocator and best-fit allocator. 

To compile: 
```$ make ```
To clean:
```$ make clean```
 
The test programs for resizeRegion() allocates three regions first, then free the region in the middle using freeRegion() and resize the first region with the deallocated region next to it.
To run the test cases for resizeRegion use :
``` 
 $ ./myAllocatorTestResize
 $ ./testResize
```
The test programs for next-fit allocator allocates three regions, deallocates the middle region by changing prefix->allocate to 0, sets the last allocated prefix to the middle region, and then allocates another region in the newly allocated region.
To run the test cases for next-fit allocator use :
```
 $ ./myAllocatorTestNF
 $ ./testNF 
```
The test programs for best-fit allocator allocates seven regions, then deallocates three "even numbered" regions, then requests to allocate memory such that the best-fit would be the second even numbered region.
To run the test cases for best-fit allocator use :
```
 $ ./myAllocatorTestBF
 $ ./testBF 
```
