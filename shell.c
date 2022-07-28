#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"/tmp/ls", "-l", "/usr/", NULL};
	printf("before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("error");
	}
	printf("after execev");
	return 0;	
}
