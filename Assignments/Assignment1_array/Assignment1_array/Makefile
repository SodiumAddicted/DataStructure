CC=gcc
OBJS=main.o CreateRandMatrix.o Operators.o ShowMatrixDetail.o ToSparseMatrix.o ToTransposition.o
TARGET=array

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
main.o: Matrix.h main.c
CreateRandMatrix.o: Matrix.h CreateRandMatrix.c
Operators.o: Matrix.h Operators.c
ShowMatrixDetail.o: Matrix.h ShowMatrixDetail.c
ToSparseMatrix.o: Matrix.h ToSparseMatrix.c
ToTransposition.o: Matrix.h ToTransposition.c
clean:
	rm -f $(TARGET) *.o
