CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g -ggdb

LDFLAGS = 

CPPFLAGS = -D_DEFAULT_SOURCE

OBJS = main.o elf.o elf_list.o

BIN = day01

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY: all
