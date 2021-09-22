/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:10:59 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/21 18:48:17 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	trim_start(const char *s1, const char *set);
size_t			trim_end(const char *s1, const char *set, size_t size);

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t			size;
	unsigned int	start;

	if (!s1 && !set)
		return (NULL);
	start = trim_start(s1, set);
	size = ft_strlen(s1);
	size = trim_end(s1, set, size);
	if (!*s1)
		return (ft_strdup(s1));
	return (ft_substr(s1, start, size));
}

unsigned int	trim_start(const char *s1, const char *set)
{
	int				i;
	unsigned int	start;

	i = 0;
	start = 0;
	while (set[i])
	{
		if (s1[start] == set[i])
		{
			start++;
			i = 0;
			continue ;
		}
		i++;
	}
	return (i);
}

size_t	trim_end(const char *s1, const char *set, size_t size)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1[size - 1] == set[i])
		{
			size--;
			i = 0;
			continue ;
		}
		i++;
	}
	return (size);
}
