#include <stdio.h>
#include <stdlib.h>


/**

  * main - Entry point

  * @argv: arguement vector

  * @argc: arguement count

  * Return: void

  */

int main(int ac, char **av)


{
	int i, k = 0;

	while (av[k])
		k++;

	for (i = 0; i < k; i++)
		printf("%s\n", av[i]);

	return (0);

}
