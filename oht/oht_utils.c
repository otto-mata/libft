/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   oht_utils.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/02/15 12:57:47 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/02/15 12:59:04 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "oht.h"

uint64_t	hash_region(void *region, size_t n)
{
	uint64_t		hash;
	unsigned char	*p;
	size_t			i;

	hash = FNV_OFFSET;
	p = region;
	i = 0;
	while (i < n)
	{
		hash ^= (uint64_t)(p[i]);
		hash *= FNV_PRIME;
		i++;
	}
	return (hash);
}

uint64_t	hash_str(char const *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (hash_region((void *)s, len));
}

uint32_t	hash_key(char const *key, int capacity)
{
	return (hash_str(key) % capacity);
}
