/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:32:45 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/15 21:28:52 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char *) s;
	chr = (unsigned char) c;
	if (n == 0)
		return (NULL);
	while (*str && n--)
	{
		if (*str == chr)
			return ((void *) str);
		str++;
	}
	if (!*str && !chr)
		return ((void *) str);
	return (NULL);
}
