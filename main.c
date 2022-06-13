#include "main.h"

int main(int argc, char **argv)
{
        /* Load config files, if any */
        /* Run command loop. */
        cshell_loop();
        
        /* Perform any shutdown/cleanup. */
        return EXIT_SUCCESS;
}

void cshell_loop(void)
{
        char *line;
        char **args;
        int status;

        do {
        printf("> ");
        line = cshell_read_line();
        args = cshell_split_line(line);
        status = cshell_execute(args);

        free(line);
        free(args);
        } while (status);
}


char *cshell_read_line(void)
{
        int bufsize = SHELL_BUFSIZE;
        int position = 0;
        char *buffer = malloc(sizeof(char) * bufsize);
        int ;

        if (!buffer) 
        {
                fprintf(stderr, "cshell: allocation error\n");
                exit(EXIT_FAILURE);
        }

        while (1) 
        {
                /* Read in a character in the infinite loop */
                cha = getchar();

                // If we hit EOF, replace it with a null character and return.
                if (cha == EOF || cha == '\n') 
                {
                        buffer[position] = '\0';
                        return buffer;
                }
                else 
                {
                        buffer[position] = cha;
                }
                position++;

                /* If buffer size exceeded, reallocate buffer. */
                if (position >= bufsize)
                {
                        bufsize += SHELL_BUFSIZE;
                        buffer = realloc(buffer, bufsize);
                        if (!buffer)
                        {
                                fprintf(stderr, "lsh: allocation error\n");
                                exit(EXIT_FAILURE);
                        }
                }
        }
}

char **cshell_split_line(char *line)
{
        int bufsize = TOKEN_BUFSIZE, position = 0;
        char **tokens = malloc(bufsize * sizeof(char*));
        char *token;

        if (!tokens) 
        {
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
        }

        token = strtok(line, TOKEN_DELIMITER);

        while (token != NULL)
        {
                tokens[position] = token;
                position++;

                if (position >= bufsize)
                {
                        bufsize += TOKEN_BUFSIZE;
                        tokens = realloc(tokens, bufsize * sizeof(char*));
                        if (!tokens)
                        {
                                fprintf(stderr, "cshell: allocation error\n");
                                exit(EXIT_FAILURE);
                        }
                }
 
                token = strtok(NULL, TOKEN_DELIMITER);
        }
        tokens[position] = NULL;
        return tokens;
}

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
                        perror("cshell");
                }
                exit(EXIT_FAILURE);
        }
        else if (pid < 0) 
        {
                /* Error forking */
                perror("cshell");
        }
        else 
        {
                /* Parent process */
                do {
                        wpid = waitpid(pid, &status, WUNTRACED);
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }

        return 1;
}
