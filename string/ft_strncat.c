/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strncat.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 13:59:32 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_strncat(char *d, char const *s, size_t n)
{
	size_t	ssz;
	size_t	dsz;

	if (!s || !d)
		return (0);
	ssz = ft_strlen(s);
	dsz = ft_strlen(d);
	ft_memcpy(d + dsz, s, ft_min(ssz + 1, n));
	*(d + ft_min(ssz + 1, n)) = 0;
	return (d);
}
