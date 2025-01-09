/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   args_validate.c                                      ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/25 10:42:05 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:55:32 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

int	args_validate(void)
{
	t_args *const	inst = args_instance();
	int				i;

	i = 0;
	if (!inst || !inst->validators)
		return (0);
	while (inst->validators[i] && !inst->error)
	{
		inst->validators[i]();
		i++;
	}
	return (!inst->error);
}
