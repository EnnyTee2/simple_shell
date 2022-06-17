#include "main.h"

/**
 * main - entry point
 * Return: exit_success (0)
 */

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


int main()
{
        /* start shell loop. */
        cshell_loop();
        
        /* shutdown/cleanup. */
        return EXIT_SUCCESS;
}
