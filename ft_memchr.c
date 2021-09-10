/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:32:45 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/09 21:56:00 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	str = (unsigned char *) s;
	chr = (unsigned char) c;
	i = 0;
	if (n == 0)
		return (NULL);
	while (str[i])
	{
		if (str[i] && i < n)
		{
			if (str[i] == chr)
			{
				return ((void *)(s + i));
			}
		}
		i++;
	}
	return (NULL);
}
