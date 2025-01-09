/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_addback.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:35:30 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_block	*gc_addback(t_block *new)
{
	t_block	*tmp;
	t_gc	*gc;

	gc = gc_instance();
	if (!(gc))
		return (0);
	if (!(gc->blocks))
	{
		gc->blocks = new;
		return (gc->blocks);
	}
	tmp = gc->blocks;
	while (tmp)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	tmp->next = new;
	return (gc->blocks);
}
