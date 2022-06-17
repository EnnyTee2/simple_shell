#include "main.h"

/**
 * cshell_split_line - splits the line to extract commands
 * @line: command stream extracted by read_line
 * Return: returns splitted tokens according to delimiter applied
 */

char **cshell_split_line(char *line)
	{
	int bufsize = TOKEN_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "cshell: allocation error\n");
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
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "cshell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOKEN_DELIMITER);
	}
	tokens[position] = NULL;
	return (tokens);
}
