#ifndef _MAIN_H_
#define _MAIN_H_
#define SHELL_BUFSIZE 1024
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIMITER " \t\r\n\a"

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void cshell_loop(void);
char *cshell_read_line(void);
char **cshell_split_line(char *line);

int shell_launch(char **args);

int cshell_builtins();
int cshell_cd(char **args);
int cshell_help(char **args);
int cshell_exit(char **args);
int cshell_execute(char **args);
