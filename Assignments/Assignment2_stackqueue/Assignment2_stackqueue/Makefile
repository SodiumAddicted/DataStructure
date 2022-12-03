CC=gcc
OBJS=main.o Infix2Postfix.c ParenthesisMatchingFunc.c PolynomialFunc.c QueueFunc.c StackFunc.c
TARGET=stackqueue

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
main.o: StackQueue.h main.c
Infix2Postfix.o: StackQueue.h Infix2Postfix.c
ParenthesisMatchingFunc.o: StackQueue.h ParenthesisMatchingFunc.c
PolynomialFunc.o: StackQueue.h PolynomialFunc.c
QueueFunc.o: StackQueue.h QueueFunc.c
StackFunc.o: StackQueue.h StackFunc.c
clean:
	rm -f $(TARGET) *.o
