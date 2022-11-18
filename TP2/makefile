CC=gcc
CFLAGS=-Wall -Wextra -g

LIBS=-lm

all: test_vector test_random bench_vector

test_vector: test_vector.o vector.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

test_vector.o: test_vector.c
	$(CC) -c -o $@ $< $(CFLAGS)

vector.o: vector.c
	$(CC) -c -o $@ $< $(CFLAGS)
	
test_random: test_random.o random.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	
test_random.o: test_random.c
	$(CC) -c -o $@ $< $(CFLAGS)

random.o: random.c
	$(CC) -c -o $@ $< $(CFLAGS)

bench_vector: bench_vector.o vector.o random.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

bench_vector.o: bench_vector.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o *~ test_vector test_random bench_vector
