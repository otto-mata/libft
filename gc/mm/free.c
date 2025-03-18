/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   free.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/09 00:08:16 by ottomata             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/11 14:26:34 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "mem_manager.h"

void	mm_free(void *p)
{
	t_mpc	*infop;

	if (!p)
		return ;
	infop = p - sizeof(t_mpc);
	infop->x = 0;
}
