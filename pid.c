#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t get;

	get = getppid();
	printf("PID is: %u\n", get);
	return 0;
}
