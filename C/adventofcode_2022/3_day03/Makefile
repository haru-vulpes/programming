CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g -ggdb
LDFLAGS = 
CPPFLAGS = -D_DEFAULT_SOURCE

###########################################################

OBJS = main.o interactor.o rucksack.o item.o
BIN = day03

###########################################################

all: $(BIN)
$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY: all
