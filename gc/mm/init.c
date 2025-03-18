/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   init.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/09 00:03:16 by ottomata             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/11 14:26:32 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "mem_manager.h"

static t_mm	__initialize_memory_manager(void)
{
	t_mm	manager;

	manager.free = &mm_free;
	manager.malloc = &mm_malloc;
	manager.realloc = &mm_realloc;
	manager.pnodes = 0;
	return (manager);
}

t_mm	*memory_manager(void)
{
	static t_mm	manager = {0};
	static int	init = 0;

	if (!init)
	{
		init = 1;
		manager = __initialize_memory_manager();
	}
	return (&manager);
}
