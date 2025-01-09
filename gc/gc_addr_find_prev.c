/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_addr_find_prev.c                                  ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/25 09:59:03 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_block	*gc_addr_find_prev(void *addr)
{
	t_gc	*gc;
	t_block	*block;

	gc = gc_instance();
	if (!gc)
		return (0);
	if (!gc->blocks)
		return (0);
	block = gc->blocks;
	while (block && block->next)
	{
		if ((unsigned long)block->next->mem == (unsigned long)addr)
			return (block);
		block = block->next;
	}
	return (0);
}
