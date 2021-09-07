#include <stdlib.h>
#include <unistd.h>
#include "libtest.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

void	test(void *dest, void *src, size_t n, char *expected_output)
{
	char	*output;

	output = (char *) ft_memmove(dest, src, n);
	if (dest != output)
		printf("Returned wrong address!\nKO");
	printf("Output:   %s\nExpected: %s\n", output, expected_output);
	while (n--)
	{
		if (*output++ != *expected_output++)
		{
			printf("KO");
			return ;
		}
	}
	printf("OK");
}

int	main(int argc, char *argv[])
{
	int		arg;
	char	*src;
	char	*dest;

	src = malloc(21 * sizeof(char));
	src = strcpy(src, "Wake Up Donnie Darko!");
	dest = src + 1;
	alarm(5);
	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		test(dest, "Wake Up", 7, "Wake UpDonnie Darko!");
	else if (arg == 2)
		test(dest, "Wake Up", 4, "WakeUp Donnie Darko!");
	else if (arg == 3)
		test(dest, src, 14, "Wake Up DonnieDarko!");
	else if (arg == 4)
		test(src, dest, 3, "akee Up Donnie Darko!");
	else if (arg == 5)
		test(dest, src, 0, "");
	return (0);
}
