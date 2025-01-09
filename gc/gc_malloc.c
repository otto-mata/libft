/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_malloc.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/18 15:26:16 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	*gc_malloc(size_t sz)
{
	t_block	*new;
	void	*mem;

	mem = malloc(sz);
	if (!mem)
		return (0);
	new = gc_newblock(mem);
	if (!new)
		return (0);
	if (!gc_addback(new))
		return (0);
	return (mem);
}
