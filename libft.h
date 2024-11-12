/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/12 14:53:11 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/**
 * @brief Checks if a character is an alphabetic letter.
 *
 * @param c The character to check.
 * @return 1 if the character is alphabetic, 0 otherwise.
 */
int		ft_isalpha(int c);

/**
 * @brief Checks if a character is a digit.
 *
 * @param c The character to check.
 * @return 1 if the character is a digit, 0 otherwise.
 */
int		ft_isdigit(int c);

/**
 * @brief Checks if a character is alphanumeric.
 *
 * @param c The character to check.
 * @return 1 if the character is alphanumeric, 0 otherwise.
 */
int		ft_isalnum(int c);

/**
 * @brief Checks if a character is an ASCII character.
 *
 * @param c The character to check.
 * @return 1 if the character is in the ASCII table, 0 otherwise.
 */
int		ft_isascii(int c);

/**
 * @brief Checks if a character is printable.
 *
 * @param c The character to check.
 * @return 1 if the character is printable, 0 otherwise.
 */
int		ft_isprint(int c);

/**
 * @brief Calculates the length of a string.
 *
 * @param s The null-terminated string.
 * @return The length of the string.
 */
size_t	ft_strlen(char const *s);

/**
 * @brief Fills a block of memory with a specified byte.
 *
 * @param d Pointer to the memory block.
 * @param c Byte to fill the memory with.
 * @param sz Number of bytes to fill.
 * @return Pointer to the memory block.
 */
void	*ft_memset(void *d, int c, size_t sz);

/**
 * @brief Copies memory from source to destination.
 *
 * @param d Destination memory block.
 * @param s Source memory block.
 * @param sz Number of bytes to copy.
 * @return Pointer to the destination memory block.
 */
void	*ft_memcpy(void *d, void const *s, size_t sz);

/**
 * @brief Safely moves memory from source to destination.
 *
 * @param d Destination memory block.
 * @param s Source memory block.
 * @param sz Number of bytes to move.
 * @return Pointer to the destination memory block.
 */
void	*ft_memmove(void *d, void const *s, size_t sz);

/**
 * @brief Sets a block of memory to zero.
 *
 * @param mem Pointer to the memory block.
 * @param sz Number of bytes to set to zero.
 */
void	ft_bzero(void *mem, size_t sz);

/**
 * @brief Copies a string to a destination with size limitation.
 *
 * @param d Destination buffer.
 * @param s Source string.
 * @param l Size of the destination buffer.
 * @return Total length of the string it tried to create.
 */
size_t	ft_strlcpy(char	*d, char const *s, size_t l);

/**
 * @brief Appends a string to a destination with size limitation.
 *
 * @param d Destination buffer.
 * @param s Source string.
 * @param l Size of the destination buffer.
 * @return Total length of the string it tried to create.
 */
size_t	ft_strlcat(char	*d, char const *s, size_t l);

/**
 * @brief Converts a character to uppercase.
 *
 * @param c The character to convert.
 * @return The modified character.
 */
int		ft_toupper(int c);

/**
 * @brief Converts a character to lowercase.
 *
 * @param s The character to convert.
 * @return The modified character.
 */
int		ft_tolower(int c);

/**
 * @brief Finds the first occurrence of a character in a string.
 *
 * @param s The string to search.
 * @param c The value to find.
 * @return Pointer to the first occurrence of the character,
 * or NULL if not found.
 */
char	*ft_strchr(char const *s, int c);

/**
 * @brief Finds the last occurrence of a character in a string.
 *
 * @param s The string to search.
 * @param c The character to find.
 * @return Pointer to the last occurrence of the character, or NULL if not found.
 */
char	*ft_strrchr(char const *s, int c);

/**
 * @brief Compares two strings up to a specified number of characters.
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @param sz Number of bytes to compare.
 * @return An integer indicating comparison result.
 */
int		ft_strncmp(char const *s1, char const *s2, size_t sz);

/**
 * @brief Searches for a byte in a memory block.
 *
 * @param mem Pointer to the memory block.
 * @param c Byte to search for.
 * @param sz Number of bytes to compare.
 * @return Pointer to the first occurrence, or NULL if not found.
 */
void	*ft_memchr(void const *mem, int c, size_t sz);

/**
 * @brief Compares two memory blocks.
 *
 * @param m1 First memory block.
 * @param m2 Second memory block.
 * @param sz Number of bytes to compare.
 * @return An integer indicating comparison result.
 */
int		ft_memcmp(void const *m1, void const *m2, size_t sz);

/**
 * @brief Locates a substring within a string up to a specified length.
 *
 * @param s1 The main string to search.
 * @param s2 The substring to locate.
 * @param n Maximum number of characters to search.
 * @return Pointer to the beginning of the located substring,
 * or NULL if not found.
 */
char	*ft_strnstr(char const *s1, char const *s2, size_t n);

/**
 * @brief Converts a string to an integer.
 *
 * @param nptr The string to convert.
 * @return The converted integer value.
 */
int		ft_atoi(char const *nptr);

/**
 * @brief Allocates and initializes memory to zero.
 *
 * @param nmemb Number of elements.
 * @param sz Size of each element.
 * @return Pointer to the allocated memory, or NULL if allocation fails.
 */
void	*ft_calloc(size_t nmemb, size_t sz);

/**
 * @brief Duplicates a string.
 *
 * @param s The string to duplicate.
 * @return Pointer to the duplicated string, or NULL if allocation fails.
 */
char	*ft_strdup(char const *s);

/**
 * @brief Extracts a substring from a string.
 *
 * @param s The main string.
 * @param start Start index of the substring.
 * @param sz Length of the substring.
 * @return Pointer to the newly created substring, or NULL if allocation fails.
 */
char	*ft_substr(char const *s, size_t start, size_t sz);

/**
 * @brief Joins two strings into a new string.
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @return Pointer to the concatenated string, or NULL if allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Trims specified characters from both ends of a string.
 *
 * @param s The string to trim.
 * @param set Set of characters to remove.
 * @return Pointer to the trimmed string, or NULL if allocation fails.
 */
char	*ft_strtrim(char const *s, char const *set);

/**
 * @brief Splits a string into an array of strings based on a delimiter.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return Null-terminated array of strings, or NULL if allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Converts an integer to a string.
 *
 * @param n The integer to convert.
 * @return Pointer to the converted string, or NULL if allocation fails.
 */
char	*ft_itoa(int n);

/**
 * @brief Applies a function to each character of a string,
 * creating a new string.
 *
 * @param s The input string.
 * @param f The function to apply.
 * @return Pointer to the new string, or NULL if allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies a function to each character of a string in place.
 *
 * @param s The input string.
 * @param f The function to apply.
 */
void	ft_striteri(char	*s, void (*f)(unsigned int, char	*));

/**
 * @brief Writes a character to a file descriptor.
 *
 * @param c The character to write.
 * @param fd The file descriptor.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Writes a string to a file descriptor.
 *
 * @param s The string to write.
 * @param fd The file descriptor.
 */
void	ft_putstr_fd(char const *s, int fd);

/**
 * @brief Writes a string with a newline to a file descriptor.
 *
 * @param s The string to write.
 * @param fd The file descriptor.
 */
void	ft_putendl_fd(char const *s, int fd);

/**
 * @brief Writes an integer to a file descriptor.
 *
 * @param n The integer to write.
 * @param fd The file descriptor.
 */
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif