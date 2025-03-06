/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_bzero.c                                           ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/09 11:01:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/06 13:53:08 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_bzero(void *mem, size_t sz)
{
	unsigned char	*uc_mem;

	if (!mem)
		return ;
	uc_mem = (unsigned char *)mem;
	while (sz--)
		*uc_mem++ = 0;
}
