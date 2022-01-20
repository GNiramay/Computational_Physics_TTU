# Computational_Physics_TTU
Programs used in computational physics course course

The programs have been tested successfully for the following computer specs:

| OS              | Ubuntu 20.04.01 |
|-----------------|-----------------|
| GNU gcc version | 9.3.0           |
| GNU make        | 4.2.1           |
| Git version     | 2.25.1          |

To see the output for an assignment, do the following
1. Compile the program using the `make` command
2. If there were no errors, an executable with extension `.app` will be generated
3. Run the executable.

# Example
The output for assignment 1 would be generated using the above steps. The terminal output would look something like the following

```
$ make
g++ -Wall -c -o Integration.o Integration.c
g++ -Wall -o Assignment1.app Assignment1.C Integration.o
g++ -Wall -c -o RootFinding.o RootFinding.c
g++ -Wall -o Assignment2.app Assignment2.C RootFinding.o
$ ./Assignment1.app
Question 1
N	Trapez.	Simpson	Bode
4	2.0670	1.9448	2.0575
8	1.8904	1.8315	1.8559
16	1.8038	1.7749	1.7791
32	1.7609	1.7466	1.7467
64	1.7396	1.7324	1.7320
128	1.7289	1.7254	1.7250

Question 2
N	Trapez.	Simpson	Bode
4	29.1249	20.1972	25.6991
8	9.6322	7.2943	7.0208
16	9.3521	7.1789	8.9318
32	4.6135	4.0739	4.0076
64	4.6440	4.1342	4.8068
128	3.5320	3.4213	3.4086

```

(Quick way to generate markdown tables: https://www.tablesgenerator.com/markdown_tables)
