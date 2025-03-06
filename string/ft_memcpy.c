/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memcpy.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 13:55:24 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memcpy(void *d, void const *s, size_t sz)
{
	unsigned char const	*src = s;
	unsigned char		*dest;

	if (!d && !s)
		return (d);
	dest = d;
	while (sz--)
		*dest++ = *src++;
	return (d);
}
