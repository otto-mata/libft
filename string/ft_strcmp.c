/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcmp.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 13:57:16 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	ft_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_strcmp(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	return (ft_memcmp(s1, s2, ft_max(ft_strlen(s1), ft_strlen(s2))));
}
