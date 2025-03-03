/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftgc_lstdelone.c                                     ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:39:01 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/03 08:25:49 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gcllist.h"

void	ftgc_lstdelone(t_gclist *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
