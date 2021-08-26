/*
	Future tests
*/

#include <stdio.h>
#include "../include/libft.h"

void	print_KO(void);
void	print_OK(void);
void	check_int(int output, int expected);
void	test_init(char *file_name);
void	print_div(void);

int	main(void)
{
	test_init("isalpha.c");
	check_int(isalpha('A'), 1);
	check_int(isalpha(5), 1);
	print_div();
	return (0);
}

void	print_KO(void)
{
	printf("\033[0;31m");
	printf("X ");
	printf("\033[0m");
}

void	print_OK(void)
{
	printf("\033[0;32m");
	printf("O ");
	printf("\033[0m");
}

void	check_int(int output, int expected)
{
	if (output == expected)
	{
		print_OK();
		return ;
	}
	print_KO();
}

void	test_init(char *file_name)
{
	printf("Testing %s:", file_name);
	print_div();
}

void	print_div(void)
{
	printf("\n--------------------\n");
}
