#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct builtin
{
    char *command;
    int (*command_func)(char **args);
} builtin_t;


extern char **environ;

/* handles ctrl_d */
void ctrl_d(int sig);
/*Duplicates a string*/
char *_strdup(char *str);
/*Tokenizer*/
char **tokenize_line(char *line);
/*Execute*/
int exec_proc(char **args, char *path);
/*Function to pointer*/
int (*is_built_in(char **args))(char **tokenized);
/*cd command*/
int exe_cd(char **args);
/*help command*/
int exe_help(char **args);
/*exit command*/
int exe_exit(char **args);

/* READS LINE */
char *read_line(void);
/*Look for the PATH*/
char * look_for_path();
/*Tokenize PATH*/
char **tokenize_path(char *line);
/*filther path*/
char * filter_path(char **path, char *command);
/* free arguements */
void free_args(char **token);

#endif /*MAIN_HEADER*/