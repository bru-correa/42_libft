/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 23:31:59 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/10 16:27:29 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	l_len;
	size_t	match;

	if (*little == '\0')
		return ((char *) big);
	i = 0;
	match = 0;
	l_len = ft_strlen(little);
	while (i < n)
	{
		if (little[match] == big[i])
			match++;
		else
			match = 0;
		if (match == l_len)
			return ((char *) &big[i - (match - 1)]);
		i++;
	}
	return (NULL);
}
