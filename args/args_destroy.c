/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   args_destroy.c                                       ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/28 15:29:59 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:57:00 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

void	args_destroy(void)
{
	t_args	*instance;
	int		iter;

	iter = 0;
	instance = args_instance();
	if (!instance)
		return ;
	gc_free(instance->validators);
	gc_free(instance->clean);
	if (instance->must_clean_args)
	{
		while (instance->args[iter])
			gc_free(instance->args[iter++]);
		gc_free(instance->args);
	}
	gc_free(instance);
}
