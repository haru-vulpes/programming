CFLAGS = -fsanitize=address -Wall -Wextra -Werror -pedantic -std=c99 -g -ggdb

CC = clang

LDFLAGS = -fsanitize=address 

CPPFLAGS = -D_DEFAULT_SOURCE

##########################################################
							##
OBJS = main.o camp_cleanup.o				##
							##
BIN = day04				        	##
						        ##
##########################################################

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.PHONY: all
