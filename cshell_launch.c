#include "main.h"

/**
 * cshell_launch - launches the shell by creating new process
 * @args: various arguments given
 * Return: int (1) success
 */

int cshell_launch(char **args)
{
        pid_t pid, wpid;
        int status;

        pid = fork();
        if (pid == 0)
        {
                /* Child process */
                if (execvp(args[0], args) == -1)
                {
                        perror("cshell:");
                }
                exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
                /* Error forking */
                perror("cshell:");
        }
        else 
        {
                /* Parent process */
                do 
                {
                        wpid = waitpid(pid, &status, WUNTRACED);
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }

        return(1);
}
