/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:45:58 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 20:19:15 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*iter;
	void	*new_content;

	map = 0;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		new_content = f(lst->content);
		iter = ft_lstnew(new_content);
		if (!iter)
		{
			ft_lstclear(&map, del);
			del(new_content);
			return (0);
		}
		ft_lstadd_back(&map, iter);
		lst = lst->next;
	}
	return (map);
}
