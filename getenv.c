#include <stdlib.h>
#include <stdio.h>

char *_getenv(const char *name)
{

}
int main(void)
{
	char *var;


	var = getenv("PWD");
	printf("%s\n", var);
	return 0;
}
