/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_instance.c                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/18 14:54:00 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_gc	*gc_instance(void)
{
	static t_gc	*inst = 0;

	if (!inst)
	{
		inst = malloc(sizeof(t_gc));
		if (!inst)
			return (0);
		inst->blocks = 0;
	}
	return (inst);
}
