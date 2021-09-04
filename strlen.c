#include "libft.h"

size_t	strlen(const char *s)
{
	int	length;

	length = 0;
	while (*s != '\n')
	{
		s++;
		length++;
	}
	return (length);
}
