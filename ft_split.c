/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:45:10 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/27 16:39:22 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Set start_pos at the first index without the delimiter
* Start to run the iterator from start_pos to the next delimeter or NULL
* Allocate another memory space for the next string with start_pos - end_pos + 1
* Set the string in the array
*/
#include "libft.h"

static char		*get_string(const char *s, char c, size_t *pos);
static char		*set_string(const char *src, char *dest, size_t start, \
															size_t end);
static size_t	count_words(const char *s, char c);

char	**ft_split(const char *s, char c)
{
	char	**output;
	size_t	*pos;
	size_t	wordn;
	char	**output_start;

	if (!s)
		return (NULL);
	pos = (size_t *) malloc(sizeof(size_t));
	if (!pos)
		return (NULL);
	*pos = 0;
	wordn = count_words(s, c);
	output = malloc((wordn + 1) * sizeof(char *));
	if (!output)
		return (NULL);
	output_start = output;
	while (s[*pos])
	{
		while (s[*pos] && s[*pos] == c)
			*pos = *pos + 1;
		if (s[*pos])
			*output++ = get_string(s, c, pos);
	}
	*output = NULL;
	free(pos);
	return (output_start);
}

static char	*get_string(const char *s, char c, size_t *pos)
{
	size_t	start_pos;
	char	*output;

	start_pos = *pos;
	while (s[*pos] != c && s[*pos])
		*pos = *pos + 1;
	output = malloc((*pos - start_pos + 2) * (sizeof(char)));
	if (!output)
		return (NULL);
	set_string(s, output, start_pos, *pos - 1);
	return (output);
}

static char	*set_string(const char *src, char *dest, size_t start, size_t end)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	while (j <= end)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

static size_t	count_words(const char *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			counter++;
		while (*s != c && *s)
			s++;
	}
	return (counter);
}

/*
int	main(void)
{
	char	*s1 = "      split       this for   me  !       ";
	char	**words;

	words = ft_split(s1, ' ');
	return (0);
}
*/
