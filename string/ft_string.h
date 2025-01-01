/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:04:32 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 22:29:03 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <stddef.h>
# include <sys/types.h>
# include <stdlib.h> 

void	*ft_memccpy(void *dest, const void *src, int c, size_t sz);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_stpcpy(char *dest, const char *s);
char	*ft_stpncpy(char *dest, const char *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strcoll(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
size_t	ft_strcspn(const char *str, const char *reject);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strncat(char *dest, const char *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strndup(const char *str, size_t n);
size_t	ft_strnlen(const char *str, size_t maxlen);
char	*ft_strpbrk(const char *str, const char *accept);
char	*ft_strrchr(const char *str, int c);
size_t	ft_strspn(const char *str, const char *spn);
char	*ft_strstr(const char *str, const char *substr);
char	*ft_strtok(char *str, const char *delim);
char	*ft_strtok_r(char *str, const char *delim, char **saveptr);
void	ft_strrev(char *str);
void	ft_bzero(void *mem, size_t sz);

#endif