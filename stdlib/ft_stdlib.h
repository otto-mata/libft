/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_stdlib.h                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/01 19:27:11 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:39:48 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
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

long	ft_a64l(const char *s);
int		ft_abs(int n);
double	ft_atof(const char *s);
int		ft_atoi(const char *s);
long	ft_atol(const char *s);
void	*ft_calloc(size_t nmemb, size_t sz);
div_t	ft_div(int a, int b);
char	*ft_getenv(const char *name);
char	*ft_l64a(long n);
long	ft_labs(long n);
ldiv_t	ft_ldiv(long a, long b);
char	*ft_itoa(int n);
void	free2d(void **ptr, int n);
void	*ft_realloc(void *mem, size_t old_sz, size_t new_sz);

#endif
