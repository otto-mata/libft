/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_delblock.c                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:39:01 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	*gc_delblock(t_block *block)
{
	t_gc *const	gc = gc_instance();
	t_block		*prev;

	if (!gc || !block)
		return (0);
	prev = gc_addr_find_prev(block->mem);
	if (!prev)
		gc->blocks = block->next;
	else
		prev->next = block->next;
	free(block->mem);
	block->mem = 0;
	free(block);
	return (0);
}
