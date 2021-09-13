/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:28:24 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/13 16:16:43 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*substr_start;

	substr = malloc(len * sizeof(char));
	substr_start = substr;
	if (len + start > ft_strlen(s))
		return (substr);
	while (len > 0)
	{
		*substr = s[start];
		len--;
		start++;
		substr++;
	}
	return (substr_start);
}
