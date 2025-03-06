/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memchr.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 13:54:12 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memchr(void const *mem, int c, size_t len)
{
	unsigned char const	*src = (unsigned char const *)mem;

	if (!mem)
		return (0);
	while (len-- > 0)
	{
		if (*src == (unsigned char)c)
			return ((void *)src);
		src++;
	}
	return (0);
}
