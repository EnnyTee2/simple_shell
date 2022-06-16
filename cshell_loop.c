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
