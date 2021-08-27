#define _XOPEN_SOURCE 700
#include <signal.h>
#include <stdio.h>

void	check_for_segv()
{
	struct sigaction sa;
	sa.sa_handler = handler_sigsegv;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGSEGV, &sa, NULL);
}

void	handler_sigsegv(int sig)
{
	fflush(stdout);
	write(1, "S ", 1);
	raise(SIGINT);
}

void	print_result(int state)
{
	if (state > 0)
	{
		printf("\033[0;32m");
		printf("O ");
	}
	else
	{
		printf("\033[0;31m");
		printf("X ");
	}
	pritnf("\033[0m");
}
