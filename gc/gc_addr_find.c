/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_addr_find.c                                       ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/23 16:06:20 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_block	*gc_addr_find(void *addr)
{
	t_gc	*gc;
	t_block	*block;

	gc = gc_instance();
	if (!gc)
		return (0);
	if (!gc->blocks)
		return (0);
	block = gc->blocks;
	while (block)
	{
		if ((unsigned long)block->mem == (unsigned long)addr)
			return (block);
		block = block->next;
	}
	return (0);
}
