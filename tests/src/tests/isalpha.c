#include <stdlib.h>
#include <unistd.h>
#include "libtest.h"
#include "libft.h"

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
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		test_isalpha('a', "1");
	else if (arg == 2)
		test_isalpha('a' + 1, "1");
	else if (arg == 3)
		test_isalpha('a' - 1, "0");
	else if (arg == 4)
		test_isalpha('z', "1");
	else if (arg == 5)
		test_isalpha('z' + 1, "0");
	else if (arg == 6)
		test_isalpha('z' - 1, "1");
	else if (arg == 7)
		test_isalpha('A', "1");
	else if (arg == 8)
		test_isalpha('A' + 1, "1");
	else if (arg == 9)
		test_isalpha('A' - 1, "0");
	else if (arg == 10)
		test_isalpha('Z' + 1, "0");
	else if (arg == 11)
		test_isalpha('Z' - 1, "1");
	else if (arg == 12)
		test_isalpha('Z', "1");
	return (0);
}
