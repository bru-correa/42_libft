/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:18:57 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/03 23:38:57 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

/* ***** Part 1 - Libc Functions ***** */

/**
 * @brief Checks if c is an alphabetic character in ASCII
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		isalpha(int c);

/**
 * @brief Checks if c is a digit in ASCII
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		isdigit(int c);

/**
 * @brief Checks for an alphanumeric character in ASCII
 *
 * @param c  Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		isalnum(int c);

/**
 * @brief Checks whether c is a 7-bit unsigned char value that fits into the
 * ASCII character set
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		isascii(int c);

/**
 * @brief Checks if C is a printable character in ASCII
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		isprint(int c);

/**
 * @brief Calculates the length of the string s, excluding the terminatig null
 * byte
 *
 * @param s Constant string to be analysed
 * @return size_t Returns the number of bytes in the string s
*/
size_t	strlen(const char *s);

/**
 * @brief Writes len bytes of value c (converted to an unsigned char) to the
 * string dest. Undefined behaviour from memset(), resulting from storage
 * overflow, will occur if len is greater than the length of the buffer dest.
 * The behaviour is also undefined if dest is an invalid pointer
 *
 * @param dest Starting address of memory to be filled
 * @param c Value to be filled
 * @param len Number of bytes to be filled
 * @return *void Returns its first argument
*/
void	*memset(void *dest, int c, size_t len);

#endif
