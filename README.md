**0x16. C - Simple Shell**

*Concepts*
For this project, we expect you to look at these concepts:

[Everything you need to know to start coding your own shell]()
[Approaching a Project]()
[All about Team Projects + Pairings + FAQ (A must read)]()
[Struggling with the sandbox? Try this: Using Docker & WSL on your local host]()


**Resources**

Read or watch:

[Unix shell]()
[Thompson shell]()
[Ken Thompson]()
[Everything you need to know to start coding your own shell concept page]()

*man or help:*

sh (Run sh as well)

**Learning Objectives**

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

**General**

Who designed and implemented the original Unix operating system
Who wrote the first version of the UNIX shell
Who invented the B programming language (the direct predecessor to the C programming language)
Who is Ken Thompson
How does a shell work
What is a pid and a ppid
How to manipulate the environment of the current process
What is the difference between a function and a system call
How to create processes
What are the three prototypes of main
How does the shell use the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
What is EOF / “end-of-file”?

**Requirements**

General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (why?)
Write a README with the description of your project
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see [Docker]()

*List of allowed functions and system calls*

access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

let’s break down the structure of the shell implementation:

Main Loop: The shell operates using a principal loop that continuously reads user input, parses it into commands and arguments, executes the commands, and then waits for more user input.

Reading Input: The shell reads user input using the getline function. This function reads an entire line from the stream, storing the address of the buffer containing the text into *lineptr. The buffer is null-terminated and includes the newline character if one was found.

Parsing Input: The shell parses the user’s input into a command and its arguments using the strtok function. This function splits a string into tokens based on a set of delimiters. In this case, it’s used to divide the input into words separated by spaces.

Executing Commands: The shell executes commands using a combination of fork, execve, and execvp functions. The fork function is used to create a new process. The execve or execvp function is then used in the child process to replace the current process image with a new one, effectively running the command.

Handling Paths: The shell handles paths using a custom function, _which. This function takes a command name and searches for it in the directories specified in the PATH environment variable. If a file with the command name is found, _which returns the full path to the command. If no file is found after checking all directories in the PATH, _which returns NULL.

Error Handling: The shell handles errors using the perror function. This function produces a message on the standard error output, beginning with a string you specify, followed by a colon and a space, and then the textual representation of the current errno value.

In C programming language, there is an external variable called `errno`. This variable is automatically assigned a code (value) when a function is called, and this code can be used to identify the type of error that has been encountered³. Different codes (values) for `errno` mean different types of errors³.

The `perror()` function in C prints a description of the last error encountered during a call to a system function⁴. When a system call fails, it usually returns -1 and sets the variable `errno` to a value describing what went wrong⁴. These values can be found in `<errno.h>`⁴.

Here are some examples of `errno` values and their descriptions⁶:
- **EPERM (1)**: Operation not permitted
- **ENOENT (2)**: No such file or directory
- **ESRCH (3)**: No such process
- **EINTR (4)**: Interrupted system call
- **EIO (5)**: I/O error
- **ENXIO (6)**: No such device or address
- **E2BIG (7)**: Argument list too long
- **ENOEXEC (8)**: Exec format error
- **EBADF (9)**: Bad file number
- **ECHILD (10)**: No child processes
- **EAGAIN (11)**: Try again
- **ENOMEM (12)**: Out of memory
- **EACCES (13)**: Permission denied
- **EFAULT (14)**: Bad address
- **ENOTBLK (15)**: Block device required

Please note that the actual error messages associated with values of `errno` can be obtained using `strerror` or directly printed using function `perror`[^10^].

Source: Conversation with Bing, 11/13/2023
(1) Error Handling in C - GeeksforGeeks. https://www.geeksforgeeks.org/error-handling-in-c/.
(2) perror(3) - Linux manual page - man7.org. https://www.man7.org/linux/man-pages/man3/perror.3.html.
(3) 131 Linux Error Codes for C Programming Language using errno. https://www.thegeekstuff.com/2010/10/linux-error-codes/.
(4) errno - C++ Users. https://cplusplus.com/reference/cerrno/errno/.
(5) how can perror and errno show different results (Linux)?. https://stackoverflow.com/questions/35489131/how-can-perror-and-errno-show-different-results-linux.
(6) When should I use perror("...") and fprintf(stderr, "...")?. https://stackoverflow.com/questions/12102332/when-should-i-use-perror-and-fprintfstderr.
(7) errno - C++ Reference - cplusplus.com. https://legacy.cplusplus.com/reference/cerrno/errno/.
(8) errno(3) - Linux manual page - man7.org. https://www.man7.org/linux/man-pages/man3/errno.3.html.
(9) Errno Values for UNIX-Type Functions - IBM. https://www.ibm.com/docs/en/i/7.4?topic=ssw_ibm_i_74/apis/unix14.htm.
(10) ERRNO Values - IBM. https://www.ibm.com/docs/SSB27H_6.2.0/fa2ti_errno_values.html.


This structure forms the backbone of the shell program, providing a framework within which the shell can read, parse, and execute commands. It’s a testament to the power and flexibility of C that such a complex program can be built using relatively simple building blocks.
