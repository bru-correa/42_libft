/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:28:24 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/08/31 21:28:46 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char 	*substr_start;

	substr = malloc(len * sizeof(char));
	substr_start = substr;
	if (len + start > ft_strlen(s))
		return (substr);
	while(len > 0)
	{
		*substr = s[start];
		len--;
		start++;
		substr++;
	}
	return (substr_start);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
