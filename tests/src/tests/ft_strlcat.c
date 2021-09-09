#include <stdlib.h>
#include <unistd.h>
#include "libtest.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

void	test(char *dest, char *src, size_t size, char *expected_output);

int	main(int argc, char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		test("Hello", " World", 12, "Hello World");
	else if (arg == 2)
		test("Wake", " Up Donnie", 8, "Wake Up");
	else if (arg == 3)
		test("Wake", " Up Donnie!", 20, "Wake Up Donnie!");
	else if (arg == 4)
		test("Wake", " Up", 1, "W");
	else if (arg == 5)
		test("Wake", " Up", 0, "");
	return (0);
}

void	test(char *dest, char *src, size_t size, char *expected_output)
{
	size_t	output_size;
	size_t	expected_size;

	expected_size = ft_strlen(dest) + ft_strlen(src);
	output_size = ft_strlcat(dest, src, size);
	printf("Output:   %s | Length: %lu\n", dest, output_size);
	printf("Expected: %s | Length: %lu\n", expected_output, expected_size);
	if (strncmp(dest, expected_output, size))
	{
		printf("Returned wrong string\nKO");
		return ;
	}
	if (output_size != expected_size)
	{
		printf("Returned wrong size\nKO");
		return ;
	}
	printf("OK");
}
