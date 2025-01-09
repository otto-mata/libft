/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_newblock.c                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:28:13 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_block	*gc_newblock(void *mem)
{
	t_block	*node;

	node = malloc(sizeof(t_block));
	if (!node)
		return (0);
	node->mem = mem;
	node->next = 0;
	return (node);
}
