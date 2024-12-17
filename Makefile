CC = clang
CFLAGS = -g -Wall -Werror -Wextra
LDLIBS = -lcs50

# List all your programs here
PROGRAMS = hello scores scrabble recover

all: $(PROGRAMS)

recover: recover.c
	$(CC) $(CFLAGS) -o recover recover.c $(LDLIBS)

clean:
	rm -f $(PROGRAMS)
	rm -f *.o filter core