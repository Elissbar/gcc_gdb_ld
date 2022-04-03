# Makefile for abcd.c
abcd: abcd.c
	gcc -o abcd abcd.c
testabcd: abcd.c
	gcc -o testabcd -g abcd.c
abcd2_1: abcd2.c printwords.c
	gcc -o abcd2_1 abcd2.c printwords.c
abcd2_2: abcd2.c printwords.c
	gcc -c abcd2.c printwords.c
	ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o abcd2_2 -Map=abcd2_map /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/9/crtbegin.o abcd2.o printwords.o -lc /usr/lib/gcc/x86_64-linux-gnu/9/crtend.o /usr/lib/x86_64-linux-gnu/crtn.o
