hello: hello.o
	./hello.o
	
hello.o: hello.c
	gcc -o hello.o hello.c

clean:
	rm *.o *.txt
