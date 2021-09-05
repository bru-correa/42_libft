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
		test(0, 64, 0);
	else if (arg == 2)
		test('A', 'Z', 1);
	else if (arg == 3)
		test(91, 96, 0);
	else if (arg == 4)
		test('a', 'z', 1);
	else if (arg == 5)
		test(123, 127, 0);
	return (0);
}

void	test(int start, int end, int expected_output)
{
	int	i;
	int	output;

	i = start;
	while (i <= end)
	{
		output = ft_isalpha(i);
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
