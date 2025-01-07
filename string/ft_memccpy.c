/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memccpy.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/12/31 17:13:42 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/07 07:22:01 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		*dest;

	src = s;
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
