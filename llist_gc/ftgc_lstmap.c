/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftgc_lstmap.c                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:45:58 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/03 08:24:39 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gcllist.h"

t_gclist	*ftgc_lstmap(t_gclist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_gclist	*map;
	t_gclist	*iter;
	void		*new_content;

	map = 0;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		new_content = f(lst->content);
		iter = ftgc_lstnew(new_content);
		if (!iter)
		{
			ftgc_lstclear(&map, del);
			del(new_content);
			return (0);
		}
		ftgc_lstadd_back(&map, iter);
		lst = lst->next;
	}
	return (map);
}
