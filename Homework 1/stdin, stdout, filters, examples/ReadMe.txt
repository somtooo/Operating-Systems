
    I/O Redirection, Filters, and Pipelines

When a process is created by the operating system, the
process is always supplied with three open streams.
These three streams are called the "standard streams".
They are
   standard input  (stdin)
   standard output (stdout)
   standard error  (stderr)

We can visualize a process as an object with three "connections"
where data (bytes) can either flow into the process or flow out
from the process.

                    process
              +-----------------+
              |                 |
          ---->>stdin    stdout>>------
              |                 |
              |          stderr>>------
              |                 |
              +-----------------+

A console application will usually have its stdin stream connected
to the computer's keyboard and its stdout and stderr streams connected
to the console window.

                    process
              +-----------------+
              |                 |
  keyboard --->>stdin    stdout>>------+---> console window
              |                 |      |
              |          stderr>>------+
              |                 |
              +-----------------+

It is important to realize that the above picture is independent of
the programming language used to write the program which is running
in the process. Every process looks like this. It is up to each
programming language to allow programs, written in that language, to
make use of this setup provided by the operating system.

Every operating system has its own way of giving a process access to
the internal data structures the operating system uses to keep track
of what each standard stream is "connected" to.

The Linux operating system gives every process three "file descriptors",

    #define  STDIN_FILENO 0,  STDOUT_FILENO 1,  STDERR_FILENO 2

Linux provides the read() and write() system calls to let a process
read from and write to these file descriptors.

The Windows operating system gives every process three "handles",
You retrieve the handles using the GetStdHandle() function with
one of these input parameters.

     STD_INPUT_HANDLE, STD_OUTPUT_HANDLE, STD_ERROR_HANDLE

Windows provides the ReadFile() and WriteFile() system calls to
let a process read from and write to these handles.


Every programming language must have a way of representing the three
standard streams and every language must provide a way to read from
the standard input stream and a way to write to the standard output
and standard error streams.

For example, here is how the three standard streams are represented
by some common languages.

  Standard C uses file objects
    FILE* stdin, stdout, stderr;

  C++ uses stream objects
    ios  std::cin, std::cout, std::cerr;

  Java uses stream objects
    InputStream System.in; PrintStream System.out, System.err;

  .net uses stream objects
    System.Console.In, System.Console.Out, System.Console.Error

The C language provides functions like getchar(), scanf(), and fscanf()
to read from stdin and it provides printf() and fprintf() to write to
stdout and stderr. On a Windows computer, C's printf() function will
be implemented using the WriteFile() system call with the STD_OUTPUT_HANDLE
handle. On a Linux computer, C's printf() function will be implemented
using the write() system call with the STDOUT_FILENO file descriptor.


Every process is created by the operating system at the request of some
other process (the parent process). When the parent process asks the
operating system to create a child process, the parent tells the operating
system how to "connect" the child's three standard streams.

At a shell command prompt, if you type a command like this,

C:\> foo > result.txt

the shell program (cmd.exe on Windows, or bash on Linux) is the parent
process. The above command tells the shell process to ask the operating
system to create a child process from the foo program. But in addition
to asking the operating system to create the child process, the shell
process also instructs the operating system to redirect the child
process's standard output to the file result.txt. So when foo runs, it
looks like this.

                 foo process
              +-----------------+
              |                 |
  keyboard --->>stdin    stdout>>----> result.txt
              |                 |
              |          stderr>>----> console window
              |                 |
              +-----------------+

Stdin and stderr have their default connections, and stdout is redirected
to the file result.txt.

If you type a command like this,

C:\> foo > result.txt < data.txt

the shell process will ask the operating system to create a child process
from the foo program and also ask the operating system to redirect the
child process's standard output to the file result.txt and redirect the
child process's standard input to the file data.txt. So when foo runs, it
looks like this.

                 foo process
              +-----------------+
              |                 |
  data.txt --->>stdin    stdout>>----> result.txt
              |                 |
              |          stderr>>----> console window
              |                 |
              +-----------------+

If you type a command like this,

C:\> foo < data.txt | bar > result.txt

the shell process will ask the operating system to create two child
processes, one from the foo program and the other from the bar program.
In addition, the shell process will ask the operating system to create
a "pipe" object and have the stdout of the foo process redirected to the
input of the pipe, and have the stdin of the bar process redirected to
the output of the pipe. Finally, the shell process will ask the operating
system to redirect the bar process's standard output to the file result.txt
and redirect the foo process's standard input to the file data.txt. So
while this command is executing, it looks like this.

              foo process                  bar process
           +---------------+            +---------------+
           |               |    pipe    |               |
 data.txt-->>stdin  stdout>>--========-->>stdin  stdout>>----> result.txt
           |               |            |               |
           |        stderr>>---+        |        stderr>>--+-> console window
           |               |   |        |               |  |
           +---------------+   |        +---------------+  |
                               |                           |
                               +---------------------------+





The two example programs in this folder 
  filter1.c
  filter2.c
are "filter" programs. They are programs that read from standard
input and write to standard output. A filter program will usually
do some manipulation of what it has read from standard input before
it writes it to standard output.

The filter1.c program converts lower case letters to upper case
and it converts upper case leters to lower case. All other 
characters are just echoed from stdin to stdout.

The filter2.c program repeats twice to standard output any upper
case letter it reads from standard input. All other characters 
are just echoed from stdin to stdout.

Use these examples to experiment with I/O redirection and, more
importantly, with "pipes". That is, use pipes to combine the two
filters together (into an inter-process pipeline).

C:\> filter1 > result.txt

C:\> filter1 < input.txt > result.txt

C:\> filter1 | filter2

C:\> filter2 | filter1

C:\> filter1 < input.txt | filter2

C:\> filter1 < input.txt | filter2 > result2.txt

C:\> filter1 < input.txt | filter2 | filter1 > result2.txt
