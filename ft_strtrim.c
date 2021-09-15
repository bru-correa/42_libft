/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:10:59 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/15 16:24:51 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	size;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (set[i])
	{
		if (*s1 == set[i])
		{
			s1++;
			i = 0;
		}
		i++;
	}
	size = ft_strlen(s1);
	i = 0;
	while (set[i])
	{
		if (s1[size - 1] == set[i])
		{
			size--;
			i = 0;
		}
		i++;
	}
	if (size != 0)
		size++;
	return (ft_substr(s1, 0, size));
}
