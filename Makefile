
all: string

INCLUDES = -I.
SRC = new_string.c

string: $(SRC)
	gcc -std=c99 $(INCLUDES) $(SRC) -o string

clean:
	rm -f *.o string

