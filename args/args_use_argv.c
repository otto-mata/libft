/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   args_use_argv.c                                      ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/25 12:26:11 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:55:36 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

void	args_use_argv(char const **argv)
{
	t_args *const	inst = args_instance();

	if (!inst || !argv)
		return ;
	inst->must_clean_args = 0;
	inst->args = (char **)argv;
}
