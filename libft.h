/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:18:57 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/11 16:08:48 by bcorrea-         ###   ########.fr       */
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
 * @param len The buffer size in bytes
 * @return *void Returns its first argument
*/
void	*ft_memset(void *dest, int c, size_t len);

/**
 * @brief Sets the first len bytes of the area starting at s to zero
 *
 * @param s Starting address
 * @param len The buffer size in bytes
 * @return void None
*/
void	ft_bzero(void *s, size_t len);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 * areas must not overlap
 *
 * @param dest Pointer to destination memory area address
 * @param src Pointer to source memory area address
 * @param n Buffer size in bytes
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
 * @param n Buffer size in bytes
 * @return void* Returns dest
*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Copies up to (size - 1) bytes from the NUL-terminated string src to
 * dest, NUL-terminating the result
 *
 * @param dest Destination string
 * @param src Source string
 * @param size Buffer size in bytes
 * @return size_t Returns the length of src
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Appends the NUL-terminated string src to the end of dst. It will
 * append at most (size - strlen(dest) - 1) bytes, NUL-terminating the result
 *
 * @param dest Destination pointer to memory area
 * @param src Source pointer to memory area
 * @param size Buffer size in bytes
 *
 * @return size_t Initial length of dest + length of src
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size);

/**
 * @brief Converts the letter c to lowercase, if possible
 *
 * @param c Letter to be converted
 * @return int  Returns the converted letter, or c if the convertion was not
 * possible
*/
int		ft_tolower(int c);

/**
 * @brief Converts the letter c to uppercase, if possible
 *
 * @param c Letter to be converted
 * @return int  Returns the converted letter, or c if the convertion was not
 * possible
*/
int		ft_toupper(int c);

/**
 * @brief Returns a pointer to the first occurrence of the character in the
 * string s
 *
 * @param s The source string
 * @param c The character to be found
 * @return char* Returns the pointer to c if found or NULL if not
*/
char	*ft_strchr(const char *s, int c);

/**
 * @brief Returns a pointer to the last occurrence of the character in the
 * string s
 *
 * @param s The source string
 * @param c The character to be found
 * @return char* Returns the pointer to c if found or NULL if not
*/
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Compares the first n bytes of s1 and s2
 *
 * @param s1 Pointer to the first string
 * @param s2 Pointer to the second string
 * @param n Number of bytes to be compared
 * @return int Returns an integer less than, equal to, or greather than zero if
 * s1 is found, respectively, to be less than, to match, or be greater than s2
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s for the
 * first instance of c. Both c and the bytes of the memory area pointed to by s
 * are interpreted as unsigned char
 *
 * @param s Source pointer to memory area
 * @param c The character to be searched
 * @param n Buffer size in bytes
 * @return void* Returns a pointer to the matching byte, if one is found. If no
 * matching byte if found, the result is unspecified
*/
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of the memory areas s1 and s2
 *
 * @param s1 First string pointer to memory area
 * @param s2 Second string pointer to memory area
 * @param n Buffer size in bytes
 * @return int Returns an integer less than, equal to, or greater than zero if
 * the first n bytes of s1 is found, respectively, to be less than, to match, or
 * be greater than the first n bytes of s2.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Locates the first occurence of the null-terminated string little in
 * the null-terminated string big
 *
 * @param big The bigger string that can contain little
 * @param little The substring in big
 * @param n The buffer size in bytes
 * @return char* If little is an empty string, big is returned; if little occurs
 * nowhere in big, NULL is returned; otherwise a pointer to the first character
 * of the first occurance of little is returned
*/
char	*ft_strnstr(const char *big, const char *little, size_t n);

/**
 * @brief Converts a character string to an integer value. The function stops
 * reading str at the first character that it cannot recognize as part of a
 * number. It ignores leading white-space characters. It does not recognize
 * decimal points or expoents
 *
 * @param str Pointer to character string
 * @return int The converted value
*/
int		ft_atoi(const char *str);

#endif
