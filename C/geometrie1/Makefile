######## POTENTIELLEMENT A CHANGER MAIS GENERALEMENT NON #######
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic
LDFLAGS =
#################################################################

########## A CHANGER A CHAQUE FOIS ###########
OBJS = geometry.o main.o

BIN = geometry
##############################################


############ PAS TOUCHE ######################
all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) -o $@  $^


.PHONY: all
################################################
