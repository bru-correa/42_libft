#define _XOPEN_SOURCE 700
#include <signal.h>
#include <unistd.h>

int	main(void)
{
	int i = 0;

	alarm(5);
	while (1)
		i++;
}
