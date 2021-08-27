#define _XOPEN_SOURCE 700
#include <signal.h>
#include <stdio.h>
#include <unistd.h>



int	main(void)
{
	char *str;
	str = "GfG";
	*(str + 1) = 'n';
	return (0);
}
