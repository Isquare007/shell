#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void read_shell(void);
void tokenize_shell(char *buf, char *buf_dup);
void exe_shell(char **argv);

int main(int argc, char **argv)
{
	read_shell();
}
void read_shell(void)
{
	char *buf = NULL;
	size_t buf_size = 1024;
	char *buf_dup;

	printf("Input command: ");
	if (getline(&buf, &buf_size, stdin) == -1)
	{
		printf("\n ......logging out. \n");
		return;
	}
	buf_dup = strdup(buf);
	tokenize_shell(buf,buf_dup);
	free(buf);
}

void tokenize_shell(char *buf, char *buf_dup)
{
	char *token;
	char delim[] = {" \n"};
	char **argv = NULL;
	int tok_count = 0, i;

	token = strtok(buf, delim);
	while (token)
	{
		tok_count++;
		token = strtok(NULL, delim);
	}
	tok_count++;

	argv = malloc(sizeof(char *) * tok_count);
	token = strtok(buf_dup, delim);
	for (i = 0; token; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	exe_shell(argv);
	free(argv);
	free(token);
}
void exe_shell(char **argv)
{
	pid_t pid = fork();

	if (pid != 0)
	{
		wait(NULL);
		read_shell();
	}
	else
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error");
		execve(argv[0], argv, NULL);
	}
}

