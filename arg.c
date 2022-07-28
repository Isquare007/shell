#include <stdio.h>
#include <stdlib.h>


/**

  * main - Entry point

  * @argv: arguement vector

  * @argc: arguement count

  * Return: void

  */

int main(char *argv[])



{
	int c = 0;
	int i, k = 0;

	while (*argv[k] != '\0')
		c++;
	for (i = 0; i < c; i++)
		printf("%s\n", argv[i]);

	return (0);

}
