#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_INPUT_LENGTH 1024
#define BUFFSIZE_STD 128
#define DELIM " \t\r\a\n"

int prompt(int argc, char **argv, char **env);
char *getLine(char *buffer, int status);
char **parse(char *line, char *delimiter);
void create_process(char *command, char **arrayStr, char **argv, char *env[]);
int accessCommand(char **arrayStr, char **argv, char *env[]);
char *_strcat(char *src, char *dest);
size_t _strlen(const char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int is_builtin_command(char *command);
void execute_builtin_command(char *command, char **args, char *env[]);
int shell_exit(char *command, char **args, char **argv);
int isnumber(char *s);
char *get_path(char **arrayStr);
void *_realloc(void *ptr, size_t new_size);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *s, int c);
int handle_path(char **arrayStr, char **argv, char **env);
void command_not_found(char **arrayStr, char **argv);
char *_strdup(const char* str);
void *_memcpy(void *dest, const void *src, size_t size);
int getPath(char **arrayStr, char **argv, char **env);
int execute_args(char **args);
int my_cd(char **args);
int my_env(char *env[]);
int my_help(char **args);
int my_exit(char **args);

#endif
