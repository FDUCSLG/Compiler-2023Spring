run: lib.ll main.ll
	llvm-link main.ll lib.ll -S -o out.ll
	lli out.ll

lib.ll: libsysy.c libsysy.h
	clang -S -emit-llvm libsysy.c -o lib.ll -O0

main.ll: a.out
	./a.out

a.out: main.c main.o prog1.o slp.o util.o print_slp.o
	cc -g main.o prog1.o slp.o util.o print_slp.o

main.o: main.c slp.h slp.c util.h util.c prog1.h prog1.c print_slp.h print_slp.c
	cc -g -c main.c

prog1.o: prog1.c slp.h util.h prog1.h
	cc -g -c prog1.c

print_slp.o: print_slp.c slp.h util.h 
	cc -g -c print_slp.c

slp.o: slp.c slp.h util.h
	cc -g -c slp.c

util.o: util.c util.h
	cc -g -c util.c

clean:
	rm -f a.out util.o prog1.o slp.o main.o print_slp.o main.ll out.ll lib.ll
