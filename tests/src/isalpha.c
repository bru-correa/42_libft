#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "libtest.h"

void	test_isalpha(char input, char *expected_output)
{
	int		output;
	char	output_string;

	output = isalpha(input);
	if (output > 0)
		output_string = '1';
	print_results(&output_string, expected_output);
}

int	main(int argc, char *argv[])
{
	int	arg;

	alarm(5);
	if (argc == 1)
		return(0);
	arg = atoi(argv[1]);
	if (arg == 1)
		test_isalpha('a', "1");
	else if (arg == 2)
		test_isalpha('5', "0");
	return(0);
}
