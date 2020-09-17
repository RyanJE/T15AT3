Q2
====================

1. argc - number od commandline arguments
./program arg1 arg2

2. argv - type char** argv
./program arg1 arg2
argv = [
    ./program,
    arg1,
    args
]


3. stdin
standard input

4. stdout
standard output

5. stderr
standard error - used to write errors or extra output to.

6. exit
terminates the program
exit(0);
exit(-1,2,3,1,1000);

int main(void) {
    return 0;
}

Q4
========================

int x = 5;
x == 5

&x

fscanf - reads from a file pointer
file pointer must have read access
stdout, stderr do not work, because they are write only

fprintf - needs write access

Q5
=========================


