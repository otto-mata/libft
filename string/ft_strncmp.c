/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strncmp.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 13:59:49 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

static size_t	ft_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	n = ft_min(n, ft_max(ft_strlen(s1), ft_strlen(s2)));
	return (ft_memcmp(s1, s2, n));
}
