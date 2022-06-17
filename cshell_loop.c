#include "main.h"

/**
 * chsell_loop - creates the shell loop
 * @line: function call for command reading
 * @args: function call for line processing
 * @status: function call for execution
 */

void cshell_loop(void)
{
        char *line;
        char **args;
        int status;

        do {
        printf("($) ");
        line = cshell_read_line();
        args = cshell_split_line(line);
        status = cshell_execute(args);

        free(line);
        free(args);
        } while (status);
}
