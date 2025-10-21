# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra
OBJS = db.o ascii_table.o main.o

# Default target
all: db_test

# Main executable
db_test: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Database object file
db.o: db.c db.h ascii_db/ascii_table.h
	$(CC) $(CFLAGS) -c db.c -o db.o

# ASCII table object file
ascii_table.o: ascii_db/ascii_table.c ascii_db/ascii_table.h
	$(CC) $(CFLAGS) -c ascii_db/ascii_table.c -o ascii_table.o

# Main test file
main.o: main.c db.h
	$(CC) $(CFLAGS) -c main.c -o main.o

# Clean build files
clean:
	rm -f $(OBJS) db_test

# Clean everything including backup files
distclean: clean
	rm -f *~ ascii_db/*~

# Phony targets
.PHONY: all clean distclean