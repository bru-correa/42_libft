#include <stdlib.h>
#include <unistd.h>
#include "libtest.h"
#include "libft.h"

void	test(int input, char *expected_output);

int	main(int argc, char *argv[])
{
	int	arg;

	alarm(5);
	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		test('0', "1");
	else if (arg == 2)
		test('9', "1");
	else if (arg == 3)
		test('0' + 1, "1");
	else if (arg == 4)
		test('0' - 1, "0");
	else if (arg == 5)
		test('9' + 1, "0");
	else if (arg == 6)
		test('9' - 1, "1");
	return (0);
}

void	test(int input, char *expected_output)
{
	char	*output;

	output = malloc(2);
	*output = (char)isdigit(input);
	if (*output != '0')
		print_results(output, expected_output);
}
