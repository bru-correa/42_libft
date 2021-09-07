/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 02:23:41 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/07 03:16:29 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*copy;

	copy = malloc(n * sizeof(*dest));
	copy = ft_memcpy(copy, src, n);
	dest = ft_memcpy(dest, copy, n);
	return (dest);
}
