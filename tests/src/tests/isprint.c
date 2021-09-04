#include <stdlib.h>
#include <unistd.h>
#include "libtest.h"
#include "libft.h"
#include <stdio.h>

void	test(int start, int end, int expected_output);

int	main(int argc, char *argv[])
{
	int	arg;

	alarm(5);
	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		test(0, ' ' - 1, 0);
	else if (arg == 2)
		test(' ', 126, 1);
	return (0);
}

void	test(int start, int end, int expected_output)
{
	int	i;
	int	output;

	i = start;
	while (i <= end)
	{
		output = isprint(i);
		if (output > 0)
			output = 1;
		printf("Current char: %d Output: %d\n", i, output);
		if (output != expected_output)
		{
			printf("KO");
			break ;
		}
		i++;
		if (i > end)
			printf("OK");
	}
}
