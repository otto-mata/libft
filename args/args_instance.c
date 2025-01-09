/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   args_instance.c                                      ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/25 09:49:36 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:56:35 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

t_args	*args_instance(void)
{
	static t_args	*inst = 0;

	if (!inst)
	{
		inst = gc_malloc(sizeof(t_args));
		if (!inst)
			return (0);
		inst->clean = 0;
		inst->count = 0;
		inst->error = 0;
		inst->args = 0;
		inst->validators = 0;
	}
	return (inst);
}
