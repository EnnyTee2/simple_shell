#include "main.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: exit_success (0)
 */

int main(int argc, char **argv)
{
        /* start shell loop. */
        cshell_loop();
        
        /* shutdown/cleanup. */
        return EXIT_SUCCESS;
}
