#include "main.h"

int exec_proc(char **args, char *path)
{
	pid_t pid;
	int status, ret;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{

		ret = execve(path, args, environ);
		if (ret == -1)
		{
			perror("Still here?, there are too many errors to fix go to fix them\n\n");
			exit(1);
		}
	}
	else
	{

		wait(&status);
	}


	return (1);
}