CC = gcc -w

my_grep: main.o

grep_flags.o: grep_flags.c grep_flags.h
	$(CC) grep_flags.c -c -o grep_flags.o

reader_utils.o: reader_utils.c grep_flags.o reader_utils.h
	$(CC) reader_utils.c grep_flags.o -c

regex_utils.o: regex_utils.c grep_flags.o regex_utils.h
	$(CC) regex_utils.c grep_flags.o -c

print_utils.o: print_utils.c grep_flags.o reader_utils.o print_utils.h
	$(CC) print_utils.c grep_flags.o reader_utils.o -c

main.o: main.c grep_flags.o grep_flags.o reader_utils.o regex_utils.o print_utils.o
	$(CC) main.c grep_flags.o reader_utils.o regex_utils.o print_utils.o -o my_grep

clean:
	rm -f my_grep grep_flags.o reader_utils.o regex_utils.o print_utils.o main.o 
