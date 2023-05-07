CC = gcc -w

.SILENT: grep_flags
.SILENT: grep_flags.o
.SILENT: reader_utils.o
.SILENT: regex_utils.o
.SILENT: main.o
.SILENT: test
.SILENT: all
.SILENT: clean

my_grep: main.o

grep_flags.o: grep_flags.c grep_flags.h
	$(CC) grep_flags.c -c

reader_utils.o: reader_utils.c reader_utils.h
	$(CC) reader_utils.c -c

regex_utils.o: regex_utils.c regex_utils.h
	$(CC) regex_utils.c -c

main.o: main.c grep_flags.o grep_flags.o reader_utils.o regex_utils.o
	$(CC) main.c grep_flags.o reader_utils.o regex_utils.o -o my_grep

test:
	/bin/bash ../../../../nimrodav/grep_tests/run_all.sh

all: my_grep	

clean:
	rm -f my_grep grep_flags.o reader_utils.o regex_utils.o main.o 
