default:
	gcc test.c -o Q1file
	./Q1file

preprocess:
	gcc -E test.c -o File2.i

compile:
	gcc -S test.c -o File2.s
	
assembly:
	gcc -c test.c -o File2.o

linking:
	gcc -c test.c -o Q1file
	./Q1file