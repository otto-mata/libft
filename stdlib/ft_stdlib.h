/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_stdlib.h                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/01 19:27:11 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/02 03:18:47 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H
# include "../ctype/ft_ctype.h"
# include "../string/ft_string.h"
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/types.h>

long				ft_a64l(const char *);
int					ft_abs(int);
double				ft_atof(const char *);
int					ft_atoi(const char *);
long				ft_atol(const char *);
void				*ft_calloc(size_t, size_t);
div_t				ft_div(int, int);
char				*ft_getenv(const char *);
char				*ft_l64a(long);
long				ft_labs(long);
ldiv_t				ft_ldiv(long, long);
int					ft_putenv(char *);
void				ft_qsort(void *, size_t, size_t, int (*)(const void *,
							const void *));
int					ft_setenv(const char *, const char *, int);
double				ft_strtod(const char *, char **);
float				ft_strtof(const char *, char **);
long				ft_strtol(const char *, char **, int);
long double			ft_strtold(const char *, char **);
unsigned long		ft_strtoul(const char *, char **, int);
int					ft_unsetenv(const char *);
char				*ft_itoa(int n);
#endif
