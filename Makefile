CC=gcc
CFLAGS=-O2 -I. -pg
OBJS=alloc.o slab.o main.o
TARGET=main
 
all: $(TARGET)
 
clean:
	rm *.o
	rm $(TARGET)
 
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)