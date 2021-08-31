#include <stdio.h>
#include <string.h>

void	print_results(char *output, char *expected)
{
	printf("Output:   %s\n", output);
	printf("Expected: %s\n", expected);
	if(strcmp(output, expected) == 0)
		printf("OK");
	else
		printf("KO");
}
