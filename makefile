Project4: stack.o btree.o main.o
	gcc -g -o Project4 stack.o btree.o main.o

main.o: main.c btree.h stack.h
	gcc -g -c main.c

stack.o: stack.c btree.h stack.h
	gcc -g -c stack.c

btree.o: btree.c btree.h stack.h
	gcc -g -c btree.c

clean:
	rm stack.o btree.o main.o Project4