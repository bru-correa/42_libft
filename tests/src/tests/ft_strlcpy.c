#include <stdlib.h>
#include <unistd.h>
#include "libtest.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

void	test(char *src, size_t size, char *expected_output);

int	main(int argc, char *argv[])
{
	int	arg;

	alarm(5);
	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		test("Wake Up Donnie", 15, "Wake Up Donnie");
	else if (arg == 2)
		test("Wake \0P Donnie", 8, "Wake ");
	else if (arg == 3)
		test("Wake Up Donnie", 0, "");
	else if (arg == 4)
		test("Wake Up!", 20, "Wake Up!");
	return (0);
}

void	test(char *src, size_t size, char *expected_output)
{
	char	*dest;
	size_t	length;

	dest = malloc(size * sizeof(char));
	length = ft_strlcpy(dest, src, size);
	printf("Output:   %s\nExpected: %s\n", dest, expected_output);
	if (length != ft_strlen(src))
	{
		printf("Returned wrong size!\n\
		Output_size:   %lu\nExpected_size: %lu\nKO", \
		length, strlen(src));
		return ;
	}
	if (strncmp(dest, expected_output, size) == 0)
		printf("OK");
	else
		printf("KO");
}
