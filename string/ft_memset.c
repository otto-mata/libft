/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_memset.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 13:55:42 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memset(void *d, int c, size_t sz)
{
	unsigned char	*ptr;

	if (!d)
		return (0);
	ptr = d;
	while (sz-- > 0)
		*ptr++ = c;
	return (d);
}
