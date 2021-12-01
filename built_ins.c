#include "main.h"

void *exe_cd(char **args)
{
	if (args[1] == NULL)
		perror("Expected path to cd");
	else
	{
		if (chdir(args[1]) != 0)
			perror("Could not change directory");
	}
	printf("%s\n", args[1]);
	return (0);
}
void *exe_help(char **args)
{
	printf("Here goes a help proc\n");
	printf("%s\n", args[0]);
	return (NULL);
}
void *exe_exit(char **args)
{
	(void)(args);
	printf("Here goes an Exit proc\n");
	exit(EXIT_SUCCESS);
}