/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:46:22 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/13 16:03:11 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s) * sizeof(char);
	dup = (char *)malloc(size);
	ft_memcpy(dup, s, size);
	return (dup);
}
