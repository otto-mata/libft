/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftgc_lstclear.c                                      ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:40:55 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/03 08:25:44 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gcllist.h"

void	ftgc_lstclear(t_gclist **lst, void (*del)(void *))
{
	t_gclist	*iter;
	t_gclist	*next;

	if (!lst || !del)
		return ;
	iter = *lst;
	while (iter)
	{
		next = iter->next;
		del(iter->content);
		gc_free(iter);
		iter = next;
	}
	*lst = 0;
}
