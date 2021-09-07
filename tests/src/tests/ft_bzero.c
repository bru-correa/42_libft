#include <stdlib.h>
#include <unistd.h>
#include "libtest.h"
#include "libft.h"
#include <stdio.h>
#include <strings.h>

static void	test(void *s, size_t len);

int	main(int argc, char *argv[])
{
	int		arg;
	char	*s;
	size_t	mem_size;

	mem_size = 42;
	s = (char *)malloc(42 * sizeof(mem_size * sizeof(s)));
	s = (char *)ft_memset(s, 'a', mem_size);
	alarm(5);
	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
		test(s, 5);
	else if (arg == 2)
		test(s, 0);
	else if (arg == 3)
		test(s, 42);
	free(s);
	return (0);
}

static void	test(void *s, size_t len)
{
	char	*output;

	ft_bzero(s, len);
	output = (char *) s;
	while (len-- > 0)
	{
		if (*output++ != 0)
		{
			printf("Detected byte not set to zero!\nKO");
			return ;
		}
	}
	printf("OK");
}
