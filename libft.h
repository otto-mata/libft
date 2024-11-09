/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/09 11:07:11 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <sys/types.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(char const *s);
void	*ft_memset(void *d, int c, size_t sz);
void	*ft_memcpy(void *d, void const *s, size_t sz);
void	*ft_memmove(void *d, void const *s, size_t sz);
void	ft_bzero(void *mem, size_t sz);
size_t	ft_strlcpy(char *d, char const *s, size_t l);
size_t	ft_strlcat(char *d, char const *s, size_t l);
char	*ft_toupper(char *s);
char	*ft_tolower(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_strrchr(char *s, char c);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_memchr(void const *mem, int c);
int		ft_memcmp(void const *m1, void const *m2, size_t sz);
char	*ft_strnstr(char const *s1, char const *s2, size_t n);
int		ft_atoi(char const *nptr);
void	*ft_calloc(size_t nmemb, size_t sz);
char	*ft_strdup(char const *s);
char	*ft_substr(char const *s, size_t start, size_t sz);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(size_t, char));
void	ft_striteri(char *s, void (*f)(size_t, char *));
void	ft_putchar_fd(char const *s, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(char const *s, int fd);

#endif