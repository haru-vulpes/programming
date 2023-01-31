CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g -fPIC
# Quand je fais #include "toto.h", va chercher également dans src/
CPPFLAGS = -Isrc/

OBJS = src/main.o src/vector.o
TEST_OBJS = tests/test_vector.o

all: vector

toto: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

test: all_tests.so
	cgreen-runner $^

# -shared: Ce que je produis c'est pas un executable, c'est une "shared
#  library" (aka un sac de plein de .o)
#  -fPIC : PIC = Position Independant Code, pour des raisons vaudous
#  une shared lib doit avec ce flag sinon ça explose
#  -lcgreen : en plus de mes .o, rajoute moi la lib (-l) cgreen dans ce
#  sac
all_tests.so: $(OBJS) $(TEST_OBJS)
	$(CC) -o $@ -shared -lcgreen $^

.PHONY: all test
