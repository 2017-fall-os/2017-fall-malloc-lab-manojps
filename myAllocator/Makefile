CFLAGS	= -g
CC	= gcc
OBJ	= myAllocatorTestResize myAllocatorTestNF myAllocatorTestBF test1 

all: $(OBJ)

myAllocatorTestResize: myAllocator.o myAllocatorTestResize.o
	$(CC) $(CFLAGS) -o $@ $^

myAllocatorTestNF: myAllocator.o myAllocatorTestNF.o
	$(CC) $(CFLAGS) -o $@ $^

myAllocatorTestBF: myAllocator.o myAllocatorTestBF.o
	$(CC) $(CFLAGS) -o $@ $^

test1: myAllocator.o malloc.o test1.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -f *.o $(OBJ) 

