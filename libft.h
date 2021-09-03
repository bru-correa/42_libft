/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:18:57 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/03 19:18:58 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ***** Part 1 - Libc Functions ***** */

/**
 * @brief Checks if c is an alphabetic character in ASCII
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int	isalpha(int c);

/**
 * @brief Checks if c is a digit in ASCII
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int	isdigit(int c);

/**
 * @brief Checks for an alphanumeric character in ASCII
 *
 * @param c  Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int	isalnum(int c);

#endif
