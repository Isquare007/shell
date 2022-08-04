#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * main - prototype
  * Return: 0
  */
int main(void)
{
	char *buffer = NULL;
	size_t len = 1024;

	while(1)
	{
		printf("$ ");
		getline(&buffer, &len, stdin);
		printf("%s", buffer);
	}
	return (0);
}
