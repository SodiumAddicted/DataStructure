CC=gcc
OBJS=main.o BinaryTree.c GetSize.c Huffman.c Infix2Binarytree.c LinkedList.c QueueFunc.c StackFunc.c
TARGET=binarytree

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
main.o: Header.h main.c
BinaryTree.o: Header.h BinaryTree.c
GetSize.o: Header.h GetSize.c
Huffman.o: Header.h Huffman.c
Infix2Binarytree.o: Header.h Infix2Binarytree.c
LinkedList.o: Header.h LinkedList.c
QueueFunc.o: Header.h QueueFunc.c
StackFunc.o: Header.h StackFunc.c

clean:
	rm -f $(TARGET) *.o
