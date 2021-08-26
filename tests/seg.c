#define _XOPEN_SOURCE 700
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handler_sigsegv(int sig)
{
	fflush(stdout);
	write(1, "S ", 1);
	raise(SIGINT);
}

int	main(void)
{
	struct sigaction sa;
	sa.sa_handler = handler_sigsegv;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGSEGV, &sa, NULL);
	printf("O ");
	printf("X ");
	char *str;
	str = "GfG";
	*(str + 1) = 'n';
	return (0);
}
