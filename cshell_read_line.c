#include "main.h"

/**
 * cshell_read_line - function to read line
 * Return: buffer (allocated memory)
 */

char *cshell_read_line(void)
{
	int bufsize = SHELL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int cha;

	if (!buffer)
	{
		fprintf(stderr, "cshell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/* Read in a character in the infinite loop */
		cha = getchar();

		/* If it gets EOF, replace it with null character, return */
		if (cha == EOF || cha == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
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
				fprintf(stderr, "cshell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
