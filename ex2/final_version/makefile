CC = gcc
FFLAGS = -Wall -Wextra
LDFLAGS = 
OBJFILES = grep_flags.c reader_utils.c regex_utils.c print_utils.c main.c 
TARGET = my_grep

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~