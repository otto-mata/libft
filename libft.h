/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:01:51 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 22:44:43 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

// Content from ft_ctype.h
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_iscntrl(int c);
int						ft_isdigit(int c);
int						ft_isgraph(int c);
int						ft_islower(int c);
int						ft_isprint(int c);
int						ft_ispunct(int c);
int						ft_isspace(int c);
int						ft_isupper(int c);
int						ft_isxdigit(int c);
int						ft_isascii(int c);
int						ft_isblank(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);

// Content from io.h
ssize_t					ft_putchar_fd(char c, int fd);
ssize_t					ft_putstr_fd(char const *s, int fd);
ssize_t					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
char					*get_next_line(int fd);

int						ft_printf(char const *fmt, ...);

// Content from ft_stdlib.h
long					ft_a64l(const char *);
int						ft_abs(int);
double					ft_atof(const char *);
int						ft_atoi(const char *);
long					ft_atol(const char *);
long long				ft_atoll(const char *);
void					*ft_calloc(size_t, size_t);
div_t					ft_div(int, int);
char					*ft_getenv(const char *);
char					*ft_l64a(long);
long					ft_labs(long);
ldiv_t					ft_ldiv(long, long);
long long				ft_llabs(long long);
lldiv_t					ft_lldiv(long long, long long);
int						ft_putenv(char *);
void					ft_qsort(void *, size_t, size_t, int (*)(const void *,
								const void *));
int						ft_setenv(const char *, const char *, int);
double					ft_strtod(const char *restrict, char **restrict);
float					ft_strtof(const char *restrict, char **restrict);
long					ft_strtol(const char *restrict, char **restrict, int);
long double				ft_strtold(const char *restrict, char **restrict);
long long				ft_strtoll(const char *restrict, char **restrict, int);
unsigned long			ft_strtoul(const char *restrict, char **restrict, int);
unsigned long long		ft_strtoull(const char *restrict, char **restrict, int);
int						ft_unsetenv(const char *);
char					*ft_itoa(int n);

// Content from str.h
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
uint64_t				ft_hashstr(void *area, size_t n);
// Content from ft_string.h
void					*ft_memccpy(void *dest, const void *src, int c,
							size_t sz);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);
char					*ft_stpcpy(char *dest, const char *s);
char					*ft_stpncpy(char *dest, const char *src, size_t n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strchr(const char *s, int c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strcoll(const char *s1, const char *s2);
char					*ft_strcpy(char *dest, const char *src);
size_t					ft_strcspn(const char *str, const char *reject);
char					*ft_strdup(const char *str);
size_t					ft_strlen(const char *str);
char					*ft_strncat(char *dest, const char *src, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strndup(const char *str, size_t n);
size_t					ft_strnlen(const char *str, size_t maxlen);
char					*ft_strpbrk(const char *str, const char *accept);
char					*ft_strrchr(const char *str, int c);
size_t					ft_strspn(const char *str, const char *spn);
char					*ft_strstr(const char *str, const char *substr);
char					*ft_strtok(char *str, const char *delim);
char					*ft_strtok_r(char *str, const char *delim,
							char **saveptr);
void					ft_strrev(char *str);
void					ft_bzero(void *mem, size_t sz);
// Content from llist.h
typedef struct s_list	t_list;

struct					s_list
{
	void				*content;
	t_list				*next;
};

t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
int						ft_lstsize(t_list *lst);
t_list					*ft_lstnew(void *content);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstiter(t_list *lst, void (*f)(void *));
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstadd_front(t_list **lst, t_list *new);
void					ft_lstadd_back(t_list **lst, t_list *new);

#endif