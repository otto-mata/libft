/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   args_prepare.c                                       ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/25 09:55:26 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:55:58 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

int	args_prepare(char const *arg)
{
	t_args *const	inst = args_instance();

	if (!inst || !arg)
		return (0);
	inst->must_clean_args = 1;
	inst->args = ft_split(arg, ' ');
	if (!(inst->args))
		return (0);
	return (1);
}
