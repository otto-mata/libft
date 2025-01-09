/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_last.c                                            ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:33:48 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_block	*gc_last(void)
{
	t_gc	*gc;
	t_block	*block;

	gc = gc_instance();
	if (!gc)
		return (0);
	block = gc->blocks;
	while (block && block->next)
		block = block->next;
	return (block);
}
