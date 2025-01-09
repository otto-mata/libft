/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_nblocks.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:32:16 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

int	gc_nblocks(void)
{
	int		i;
	t_gc	*gc;
	t_block	*iter;

	gc = gc_instance();
	i = 0;
	iter = gc->blocks;
	while (iter)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}
