#define _XOPEN_SOURCE 700
#include <signal.h>

int	main(void)
{
	raise(SIGABRT);
}
