#include "main.h"

/*
 * builtin_string - list to contain all strings
 * builtin_funcs - array pointer to store bultin command addresses
 */

char (*builtin_string[]) = { "cd", "help", "exit" };

int (*builtin_funcs[]) (char **) = { &cshell_cd, &cshell_help, &cshell_exit };

/**
 * cshell_builtin_num - get the number of items in builtin_string.
 * Return: int, number of elements.
 */

int cshell_builtin_num()
{
	return (sizeof(builtin_string) / sizeof(char *));
}

/**
 * cshell_cd - handle cd errors
 * @args: list of arguments
 * Return: (1) success.
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

/**
 * cshell_help - handle and display the help messages
 * Return: 1
 */

int cshell_help()
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

/**
 * cshell_exit - exit the shell
 * Return: 0 (done)
 */

int cshell_exit()
{
	return (0);
}

/**
 * cshell_execute - execute program
 * @args: list of arguments
 * Return: call the launch function
 */

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

	return (cshell_launch(args));
}
