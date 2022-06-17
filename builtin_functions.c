#include "main.h"

/*
  Builtin function implementations as follows:
*/


int cshell_cd(char **args)
{
        if (args[1] == NULL)
        {
                fprintf(stderr, "cshell: expected argument to \"cd\"\n");
        } 
        else 
        {
                if (chdir(args[1]) != 0)
                {
                        perror("cshell:");
                }
        }
        return (1);
}

int cshell_help(char **args)
{
        int i;
        printf("A Simple Shell Written in C\n");
        printf("Type program names and desired arguments, then press enter.\n");
        printf("The following are the built in programs:\n");

        for (i = 0; i < cshell_builtin_num(); i++)
        {
                printf("  %s\n", builtin_string[i]);
        }

        return (1);
}

int cshell_exit(char **args)
{
        return (0);
}

int cshell_execute(char **args)
{
        int i;

        if (args[0] == NULL)
        {
                /* An empty command was entered */
                return (1);
        }

        for (i = 0; i < cshell_builtin_num(); i++) 
        {
                if (strcmp(args[0], builtin_string[i]) == 0)
                {
                        return ((*builtin_funcs[i])(args));
                }
        }

        return cshell_launch(args);
}
