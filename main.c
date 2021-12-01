#include "main.h"

int main(int argc, char **argv, char **env)
{
	(void)(argv);
	(void)(argc);
	(void)(env);

	char *entry_info = NULL, **tokenized, **token_path;
	
	char *path_dir = NULL;
	void *(*func_builtin)(char **);

	int fd_read, tty = 1, status, i = 0;
	size_t len = 0;

	if (isatty(STDIN_FILENO) == 0)
		tty = 0;

	do
	{
		if (tty == 1) /*Interactive Mode*/
			write(STDOUT_FILENO, "($H3LL) - ", 10);

		fflush(stdin);
		/* READ */
		fd_read = getline(&entry_info, &len, stdin);
		if (fd_read == -1)
			return (-1);
		/*Split or tokenize the input*/
		tokenized = tokenize_line(entry_info);
		/*Cheks if it is built in or isn't*/
		func_builtin = is_built_in(tokenized);
		/*Execute*/
		if (func_builtin == NULL)
		{
			path_dir = look_for_path(env);
			token_path = tokenize_path(path_dir);
			while (token_path[i])
			{
				printf("%s\n", token_path[i]);
				i++;
			}
			

			/*path = filter_path(tokenized[0], token_path);*/
			status = exec_proc(tokenized, env);
		}
		else
			func_builtin(tokenized);

	} while (status);

	return (0);
}