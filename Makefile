CC=gcc
CFLAGS=-Wall -Wextra
OBJS=db.o ascii_table.o

all: db

db: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

db.o: db.c
	$(CC) $(CFLAGS) -c db.c -o db.o
ascii_table.o: ascii_db/ascii_table.c
	$(CC) $(CFLAGS) -c ascii_db/ascii_table.c -o ascii_table.o

clean:
	rm -f $(OBJS) db
.PHONY: all clean

