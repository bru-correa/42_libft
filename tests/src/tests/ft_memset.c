#include <stdlib.h>
#include <unistd.h>
#include "libtest.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

void	test(void *dest, int c, size_t len);

int	main(int argc, char *argv[])
{
	int		arg;
	void	*dest;
	size_t	mem_size;

	alarm(5);
	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	mem_size = 42;
	dest = malloc(mem_size * sizeof(dest));
	dest = memset(dest, '_', mem_size);
	if (arg == 1)
		test(dest, 'a', mem_size);
	else if (arg == 2)
		test(dest, 'b', 10);
	else if (arg == 3)
		test(dest, '\n', 5);
	else if (arg == 4)
		test(dest, 0, 1);
	else if (arg == 5)
		test(dest, '+', 19);
	else if (arg == 6)
		test(dest, 'f', 0);
	free(dest);
	return (0);
}

void	test(void *dest, int c, size_t len)
{
	if (dest != ft_memset(dest, c, len))
		printf("Returned the wrong memory address!\nKO");
	else
		printf("OK");
}
