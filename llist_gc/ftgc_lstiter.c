/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftgc_lstiter.c                                       ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:44:44 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/03 08:26:08 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gcllist.h"

void	ftgc_lstiter(t_gclist *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
