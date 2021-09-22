/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:19:04 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/22 18:47:50 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_digit(unsigned int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n >= 0)
	{
		un = (unsigned int) n;
	}
	else
	{
		un = (unsigned int)(n * -1);
		write(fd, (char *) '-', 1);
	}
	write_digit(un, fd);
}

static void	write_digit(unsigned int n, int fd)
{
	char	c;

	if (n / 10 > 0)
		write_digit(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
