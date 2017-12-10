CFLAGS	= -g
CC	= gcc
OBJ	= myAllocatorTestResize myAllocatorTestNF myAllocatorTestBF testResize testNF testBF 

all: $(OBJ)

myAllocatorTestResize: myAllocator.o myAllocatorTestResize.o
	$(CC) $(CFLAGS) -o $@ $^

myAllocatorTestNF: myAllocator.o myAllocatorTestNF.o
	$(CC) $(CFLAGS) -o $@ $^

myAllocatorTestBF: myAllocator.o myAllocatorTestBF.o
	$(CC) $(CFLAGS) -o $@ $^

testResize: myAllocator.o malloc.o testResize.o
	$(CC) $(CFLAGS) -o $@ $^

testNF: myAllocator.o malloc.o testNF.o
	$(CC) $(CFLAGS) -o $@ $^

testBF: myAllocator.o malloc.o testBF.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o $(OBJ) 

