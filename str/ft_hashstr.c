/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_hashstr.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/01 22:32:32 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/02 03:18:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

uint64_t	ft_hashstr(void *area, size_t n)
{
	uint64_t		hash;
	unsigned char	*p;
	size_t			i;

	hash = FNV_OFFSET;
	p = area;
	i = 0;
	while (i < n)
	{
		hash ^= (uint64_t)(p[i]);
		hash *= FNV_PRIME;
		i++;
	}
	return (hash);
}
