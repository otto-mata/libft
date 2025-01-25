/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   str.h                                                ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/01 20:26:38 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/25 12:26:35 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H
# include "../gc/gc.h"
# include "../stdlib/ft_stdlib.h"
# include "../string/ft_string.h"
# include <stddef.h>

# define FNV_OFFSET 14695981039346656037UL
# define FNV_PRIME 1099511628211UL

typedef struct s_string	t_string;

struct					s_string
{
	unsigned long		len;
	unsigned long		sz;
	char				*content;
};

/**
 * @brief Extracts a substring from a string.
 *
 * @param s The main string.
 * @param start Start index of the substring.
 * @param sz Length of the substring.
 * @return Pointer to the newly created substring, or NULL if allocation fails.
 */
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
/**
 * @brief Joins two strings into a new string.
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @return Pointer to the concatenated string, or NULL if allocation fails.
 */
char					*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Trims specified characters from both ends of a string.
 *
 * @param s The string to trim.
 * @param set Set of characters to remove.
 * @return Pointer to the trimmed string, or NULL if allocation fails.
 */
char					*ft_strtrim(char const *s, char const *set);

/**
 * @brief Splits a string into an array of strings based on a delimiter.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return Null-terminated array of strings, or NULL if allocation fails.
 */

/**
 * @brief Applies a function to each character of a string,
 * creating a new string.
 *
 * @param s The input string.
 * @param f The function to apply.
 * @return Pointer to the new string, or NULL if allocation fails.
 */
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));

/**
 * @brief Applies a function to each character of a string in place.
 *
 * @param s The input string.
 * @param f The function to apply.
 */
void					ft_striteri(char *s, void (*f)(unsigned int, char *));

uint64_t				ft_hashstr(void *area, size_t n);
t_string				*expstr_new(unsigned long start_sz);
int						expstr_append(t_string *str, char val);
void					expstr_destroy(t_string **str);
char					*replace(char *in, char *sub, char *by);
char					**ft_split(char const *s, char c);
char					*ftgc_strjoin(char const *s1, char const *s2);
char					*ftgc_substr(char const *s, unsigned int start,
							size_t len);
#endif
