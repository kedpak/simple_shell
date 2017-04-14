# simple_shell

## DESCRIPTION
A simple shell created for Holberton School as a partner project with Hunter Casbeer (@spacex3ngineer) & Kevin Pak (@kpak).

## QUICK START
To start up simple_shell, compile using `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`.

```
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
```

Execute
```
./hsh

```
## SYNOPSIS
simple_shell [command_string | file]

## DESCRIPTION
simple_shell is an sh-compatible command language interpreter that executes commands read from the standard input or from a file.

### Overview
The simple_shell is a command that reads lines from either a file or the terminal, interprets them, and generally executes other commands.  It is the program that is running when the user runs gcc -Wall -Werror -Wextra -pedantic *.c -o hsh and runs the executable file, ./hsh. It incorporates many features to aid interactive use and has the advantage that the interpretative language is common to both interactive and non-interactive use (shell scripts).  That is, commands can be typed directly to the running shell or can be put into a file and the file can be executed directly by the shell.

For this project, we were limited to using a few 

### Simple Commands
 If a simple command has been recognized, the shell performs the following actions:

 1.   Leading words of the form “name=value” are stripped off and assigned to the environment of the simple command.  Redirection operators and their arguments (as described below) are stripped off and saved for processing.

 2.   The remaining words are expanded, and the first remaining word is considered the command name and the command is located.  The remaining words are considered the arguments of the command.  If no command name resulted, then the “name=value” variable assignments recognized in item 1 affect the current shell.

###Interactive and Non-Interactive Mode
To execute a command in Interactive Mode simply type in a command such as “ls”.  For Non-Interactive Mode use double quotes around commands. Ex: “echo” | “/bin/ls”

### Builtins
This section lists the builtin commands which are builtin because they need to perform some operation that can't be performed by a separate process. 

#### env  [-] [NAME=VALUE]... [COMMAND [ARG]...]
Prints out the current environment.

#### exit [exitstatus]
Terminate the shell process.  If exitstatus is given it is used as the exit status of the shell; otherwise the exit status of the preceding command is used.

### external functions
The simple shell will support all functions that can be found within a PATH

#### examples
ls, cat, and grep.p


### Files
0_shell.c - the main function that has 3 main functions that execute in addition to allow interactive and non-interactive mode.
1_getline.c - obtain the user input and return a string
2_tokenize.c - separate string into tokens
4_execute.c - create child process, check PATH and execute any files that match with the tokens. From 4_execute the follow files build off each other:
	    1) _path.c - called in 4_execute, checks if the command is found in the path
	    2) path_linkedlist.c - where various custom list functions are found and where the path is manipulated into a linked list
	    3) _get_env.c - where the path is obtained before being separated into nodes in the _build_list function.

holberton.h - contains all the prototypes for the functions used as well as the struct for building the path in the form of a linked list.

string_functions.c - custom string functions used in various files
_realloc.c - custom realloc function used in various files

NOTE:
3_builtins.c - at this time this file is empty. We intended to include some built-ins but ran out of time.
Additionally we did not have enough time to check for alias

### Known Bugs
1) “ls ARGUEMENTS“ - this is not supposed to execute
2)     /bin/ls
       /bin/ls
       /bin/ls
This is should execute ls 3 times but does not at this time.
