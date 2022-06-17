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
int cshell_help(void);
int cshell_exit(void);
int cshell_execute(char **args);
int cshell_builtin_num(void);

#endif
