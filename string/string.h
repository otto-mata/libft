/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:04:32 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/31 18:38:53 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# include <bits/types/locale_t.h>
# include <stddef.h>
# include <sys/types.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t sz);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_stpcpy(char *d, const char *s);
char	*ft_stpncpy(char *d, const char *s, size_t n);
char	*ft_strcat(char *d, const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strcoll(const char *s1, const char *s2);
char	*ft_strcpy(char *d, const char *s);
size_t	ft_strcspn(const char *s, const char *reject);
char	*ft_strdup(const char *);
size_t	ft_strlen(const char *);
char	*ft_strncat(char *, const char *, size_t);
int		ft_strncmp(const char *, const char *, size_t);
char	*ft_strncpy(char *, const char *, size_t);
char	*ft_strndup(const char *, size_t);
size_t	ft_strnlen(const char *s , size_t maxlen);
char	*ft_strpbrk(const char *, const char *);
char	*ft_strrchr(const char *, int);
size_t	ft_strspn(const char *, const char *);
char	*ft_strstr(const char *, const char *);
char	*ft_strtok(char *, const char *);
char	*ft_strtok_r(char *, const char *, char **);

#endif