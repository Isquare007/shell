#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include <string.h>

void read_cl(void);
void token(char *buf, char *buf_dup);
void exec_cl(char **argv);

int main(int argc, char *argv[])
{
	read_cl();
}
void read_cl(void)
{
	char *buf = NULL;
	size_t buf_size = 1024;
	int read;
	char *buf_dup;

	printf("Input command: ");
	read = getline(&buf, &buf_size, stdin);
	if (read == -1)
	{
		printf("\n....logging out \n");
		return;
	}
	buf_dup = strdup(buf);
	token(buf, buf_dup);
	free(buf);
}

void token(char *buf, char *buf_dup)
{
	char *token;
	char *delim = " \n";
	char **argv = NULL;
	int num_tok = 0, i;

	token = strtok(buf, delim);
	while (token)
	{
		num_tok++;
		token = strtok(NULL, delim);
	}
	num_tok++;
	argv = malloc(sizeof(char *) * num_tok);
	token = strtok(buf_dup, delim);
	for (i = 0; token; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	exec_cl(argv);
	free(argv);
	free(token);
}
void exec_cl(char **argv)
{
	pid_t pid;
	pid = fork();

	if (pid != 0)
	{
		wait(NULL);
		read_cl();
	}
	else
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("input command again");
		execve(argv[0], argv, NULL);
	}
}
