/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memccpy.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/12/31 17:13:42 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/02 03:17:44 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void *ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char const	*src = s;
	unsigned char		*dest;

	if (!d && !s)
		return (d);
	dest = d;
	while (n--)
	{
		*dest++ = *src++;
		if (*(dest - 1) == (unsigned char)c)
			return (dest);
	}
	return (0);
}
