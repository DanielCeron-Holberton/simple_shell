#include "main.h"
#define buffSTD 64

char **tokenize_line(char *line)
{
	int buff_std = buffSTD, i = 0;
	char *temp_token = NULL;
	char **token = malloc(buff_std * sizeof(char *));

	if (token == NULL)
		exit(-1);
	temp_token = strtok(line, " \t\n");

	while (temp_token)
	{
		token[i] = temp_token;
		i++;

		if (i >= buff_std)
		{
			buff_std += buffSTD;
			token = realloc(token, buff_std * sizeof(char *));
			if (token == NULL)
				exit(-1);
		}
		temp_token = strtok(NULL, " \t\n");
	}
	token[i] = NULL;

	return (token);
}

char **tokenize_path(char *line)
{
	int buff_std = buffSTD, i = 0;
	char *temp_token = NULL;
	char **token = malloc(buff_std * sizeof(char *));

	if (token == NULL)
		exit(-1);
	temp_token = strtok(line, ":");

	while (temp_token)
	{
		token[i] = temp_token;
		i++;

		if (i >= buff_std)
		{
			buff_std += buffSTD;
			token = realloc(token, buff_std * sizeof(char *));
			if (token == NULL)
				exit(-1);
		}
		temp_token = strtok(NULL, ":");
	}
	token[i] = NULL;

	return (token);
}