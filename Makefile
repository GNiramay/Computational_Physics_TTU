CXX	= g++
CFLAGS	= -Wall
DIR	= -I.
all: Assignment1.app Assignment2.app

Assignment1.app:  Assignment1.C Integration.o
	$(CXX) -Wall -o $@ $^

Assignment2.app:  Assignment2.C RootFinding.o
	$(CXX) -Wall -o $@ $^

%.o: %.c
	$(CXX) -Wall -c -o $@ $^

clean:
	rm -f $(wildcard *.o) $(wildcard *.app)
