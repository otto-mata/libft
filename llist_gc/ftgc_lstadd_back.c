/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftgc_lstadd_back.c                                   ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:35:30 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/03 08:25:28 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gcllist.h"

void	ftgc_lstadd_back(t_gclist **lst, t_gclist *new)
{
	t_gclist	*tmp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	tmp->next = new;
}
