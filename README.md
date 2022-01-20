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
4	1.6536	1.5559	1.6460
8	1.6804	1.6280	1.6497
16	1.6977	1.6705	1.6745
32	1.7075	1.6937	1.6938
64	1.7128	1.7058	1.7053
128	1.7155	1.7120	1.7116

Question 2
N	Trapez.	Simpson	Bode
4	23.2999	16.1577	20.5593
8	8.5620	6.4838	6.2407
16	8.8020	6.7567	8.4064
32	4.4737	3.9504	3.8862
64	4.5726	4.0706	4.7329
128	3.5046	3.3948	3.3821

```

(Quick way to generate markdown tables: https://www.tablesgenerator.com/markdown_tables)
