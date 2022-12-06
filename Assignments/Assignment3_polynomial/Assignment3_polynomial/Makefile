CC=gcc
OBJS=main.o ArrFunc.c PolynomialFunc.c PolyOp.c
TARGET=polynomial

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
main.o: Header.h main.c
ArrFunc.o: Header.h ArrFunc.c
PolynomialFunc.o: Header.h PolynomialFunc.c
PolyOp.o: Header.h PolyOp.c
clean:
	rm -f $(TARGET) *.o
