CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g -ggdb

LDFLAGS = 

CPPFLAGS = -D_DEFAULT_SOURCE

OBJS = main.o parse.o work_zone.o

BIN = day05

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY: all
