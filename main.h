<<<<<<< HEAD
#ifndef _MAIN_H_
#define _MAIN_H_
#define SHELL_BUFSIZE 1024
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIMITER " \t\r\n\a"

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

void cshell_loop(void);
char *cshell_read_line(void);
char **cshell_split_line(char *line);

int cshell_launch(char **args);

int cshell_builtins();
int cshell_cd(char **args);
int cshell_help(char **args);
int cshell_exit(char **args);
int cshell_execute(char **args);
int cshell_builtin_num();

#endif
=======
#ifndef _MAIN_H_
#define _MAIN_H_
#define SHELL_BUFSIZE 1024
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIMITER " \t\r\n\a"

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

void cshell_loop(void);
char *cshell_read_line(void);
char **cshell_split_line(char *line);

int cshell_launch(char **args);

int cshell_builtins();
int cshell_cd(char **args);
int cshell_help(char **args);
int cshell_exit(char **args);
int cshell_execute(char **args);
int cshell_builtin_num();

/*
  List of builtin commands, followed by their corresponding functions.
 */

char *builtin_string[] = {
        "cd",
        "help",
        "exit"
};

int (*builtin_funcs[]) (char **) = {
        &cshell_cd,
        &cshell_help,
        &cshell_exit
};

int cshell_builtin_num()
{
        return (sizeof(builtin_string) / sizeof(char *));
}

#endif
>>>>>>> 3a74c2e1adfdc24530fed4fabc5fb7475e7be479
