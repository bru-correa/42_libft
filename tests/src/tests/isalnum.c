#include <stdlib.h>
#include <unistd.h>
#include "libtest.h"
#include "libft.h"

void	test(char range_start, char range_end, char *expected_output);

int	main(int argc, char *argv[])
{
	int	arg;

	alarm(5);
	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		test('a', 'z', "1");
	else if (arg == 2)
		test('A', 'Z', "1");
	else if (arg == 3)
		test('0', '9', "1");
	else if (arg == 4)
		test(0, '0' - 1, "0");
	else if (arg == 5)
		test('9' + 1, 'A' - 1, "0");
	else if (arg == 6)
		test('Z' + 1, 'a' - 1, "0");
	else if (arg == 7)
		test('z' + 1, 127, "0");
	return (0);
}

void	test(char range_start, char range_end, char *expected_output)
{
	char	c;
	char	output;

	c = range_start;
	output = '1';
	while (c <= range_end)
	{
		if ((char)isalnum((int)c) != *expected_output)
		{
			output = '0';
			break ;
		}
		c++;
	}
	print_results(&output, expected_output);
}
