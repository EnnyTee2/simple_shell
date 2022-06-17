#include "main.h"

/**
 * main - entry point
 * @argc: argument count
 * Return: exit_success (0)
 */

int main(int argc)
{
        /* start shell loop. */
        (void) argc;
        cshell_loop();
        
        /* shutdown/cleanup. */
        return EXIT_SUCCESS;
}
