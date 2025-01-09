/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_addfront.c                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:30:42 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_block	*gc_addfront(t_block *new)
{
	t_gc	*gc;

	gc = gc_instance();
	if (!gc || !new)
		return (0);
	new->next = gc->blocks;
	gc->blocks = new;
	return (new);
}
