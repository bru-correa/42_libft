#include <stdlib.h>
#include <unistd.h>
#include "libtest.h"
#include "libft.h"
#include <stdio.h>

void	test(char *input, size_t expected_output);

int	main(int argc, char *argv[])
{
	int	arg;

	alarm(5);
	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		test("Hello", 5);
	else if (arg == 2)
		test("Wake Up Donnie!", 15);
	else if (arg == 3)
		test("", 0);
	else if (arg == 4)
		test(" ", 1);
	return (0);
}

void	test(char *input, size_t expected_output)
{
	size_t	output;

	output = strlen(input);
	printf("Length: %lu\n", output);
	if (output != expected_output)
		printf("KO");
	else
		printf("OK");
}
