.PHONY = Life clean

CC = gcc

FLAG = -Wall
OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c))

%.o: %.c %.h
	$(CC) $(Flag) -c $< -o $@


Life: $(OBJECTS)
	$(CC) -o Life $(OBJECTS)

clean:
	rm  $(OBJECTS) Life


# $(wildcard *.c) - lista wszystkich plikow .c
# $(patsubst %.c,%.o,$(wildcard *.c)) - zamiana suffixu '.c' na '.o' dla wszystkich plikow .c
