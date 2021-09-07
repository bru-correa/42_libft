#include <stdlib.h>
#include <unistd.h>
#include "libtest.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

static void	test(char *src, size_t n, char *expected_output);

int	main(int argc, char *argv[])
{
	int		arg;
	char	*string;

	string = calloc(21, sizeof(string));
	string = ft_memcpy(string, "Wake Up Donnie Darko!", 21);
	alarm(5);
	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		test (string, 11, "Hello World");
	else if (arg == 2)
		test (string, 5, "Hello");
	return (0);
}

static void	test(char *src, size_t n, char *expected_output)
{
	char	*dest;

	dest = calloc(n, sizeof(dest));
	dest = (char *) ft_memcpy(dest, src, n);
	if (strncmp(dest, expected_output, n))
		printf("OK");
	else
		printf("KO");
}
