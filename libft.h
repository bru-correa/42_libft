/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:18:57 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/07 02:22:47 by bcorrea-         ###   ########.fr       */
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
int		ft_isalpha(int c);

/**
 * @brief Checks if c is a digit in ASCII
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		ft_isdigit(int c);

/**
 * @brief Checks for an alphanumeric character in ASCII
 *
 * @param c  Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		ft_isalnum(int c);

/**
 * @brief Checks whether c is a 7-bit unsigned char value that fits into the
 * ASCII character set
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		ft_isascii(int c);

/**
 * @brief Checks if C is a printable character in ASCII
 *
 * @param c Character to be analysed
 * @return int Returns 0 if false and nonzero if true
*/
int		ft_isprint(int c);

/**
 * @brief Calculates the length of the string s, excluding the terminatig null
 * byte
 *
 * @param s Constant string to be analysed
 * @return size_t Returns the number of bytes in the string s
*/
size_t	ft_strlen(const char *s);

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
void	*ft_memset(void *dest, int c, size_t len);

/**
 * @brief Sets the first len bytes of the area starting at s to zero
 *
 * @param s Starting address
 * @param len The length in bytes
 * @return void None
*/
void	ft_bzero(void *s, size_t len);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 * areas must not overlap
 *
 * @param dest Pointer to destination memory area address
 * @param src Pointer to source memory area address
 * @param n Number of bytes to be copied
 * @return void* Returns dest
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 * areas may overlap: copying takes place as though the bytes in src are first
 * copied into a temporary array that does not overlap src or dest, and the
 * bytes are then copied from the temporary array to dest
 *
 * @param dest Pointer to destination memory area
 * @param src Pointer to source memory area
 * @param n Number of bytes that will be copied
 * @return void* Returns dest
*/
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif
