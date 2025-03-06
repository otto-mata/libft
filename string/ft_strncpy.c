/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strncpy.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 14:00:06 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strncpy(char *d, char const *s, size_t n)
{
	size_t	srclen;

	if (!s || !d)
		return (0);
	srclen = ft_strlen(s);
	if (srclen < n)
		ft_memcpy(d, s, srclen + 1);
	else if (n > 0)
	{
		ft_memcpy(d, s, n - 1);
		d[n - 1] = '\0';
	}
	return (d);
}
