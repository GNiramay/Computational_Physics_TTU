CXX	= g++
CFLAGS	= -Wall
DIR	= -I.
all: Assignment1.app Assignment2.app Assignment3.app Assignment4.app Assignment5.app Assignment6.app Assignment7.app Assignment8.app

Assignment1.app:  Assignment1.C Integration.o
	$(CXX) $(CFLAGS) -o $@ $^

Assignment2.app:  Assignment2.C RootFinding.o
	$(CXX) $(CFLAGS) -o $@ $^

Assignment3.app:  Assignment3.C ODE.o
	$(CXX) $(CFLAGS) -o $@ $^

Assignment4.app:  Assignment4.C ODE.o
	$(CXX) $(CFLAGS) -o $@ $^

Assignment5.app:  Assignment5.C
	$(CXX) $(CFLAGS) -o $@ $^

Assignment6.app:  Assignment6.C
	$(CXX) $(CFLAGS) -o $@ $^

Assignment7.app:  Assignment7.C Integration.o
	$(CXX) $(CFLAGS) -o $@ $^

Assignment8.app:  Assignment8.C Integration.o
	$(CXX) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CXX) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(wildcard *.o) $(wildcard *.app)
