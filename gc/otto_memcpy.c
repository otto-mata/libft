/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   otto_memcpy.c                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	*otto_memcpy(void *d, void const *s, size_t sz)
{
	unsigned char const	*src = s;
	unsigned char		*dest;
	size_t				i;

	if (!d && !s)
		return (d);
	dest = d;
	i = 0;
	while (i < sz)
	{
		dest[i] = src[i];
		i++;
	}
	return (d);
}
