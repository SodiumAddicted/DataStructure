CC=gcc
OBJS=main.o ArrFunc.c PolynomialFunc.c PolyOp.c
TARGET=polynomial

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
main.o: Header.h main.c
ArrFunc.o: StackQueue.h ArrFunc.c
PolynomialFunc.o: StackQueue.h PolynomialFunc.c
PolyOp.o: StackQueue.h PolyOp.c
clean:
	rm -f $(TARGET) *.o
