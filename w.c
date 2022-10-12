#include <unistd.h>
int main(void)
{
	char c;

	c = ('5');
	write(0, &c, 1);
	return 0;
}
