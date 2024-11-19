/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:45:58 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/18 18:20:23 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_clear_all(t_list **lst, void (*del)(void *))
{
	t_list	*iter;
	t_list	*next;

	iter = *lst;
	while (iter)
	{
		del(iter->content);
		next = iter->next;
		free(iter);
		iter = next;
	}
	*lst = 0;
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*iter;
	t_list	*tmp;

	if (!lst)
		return (0);
	map = ft_lstnew(f(lst->content));
	if (!map)
		return (0);
	lst = lst->next;
	iter = map;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
			return (ft_clear_all(&map, del));
		iter->next = tmp;
		lst = lst->next;
		iter = iter->next;
	}
	iter->next = 0;
	return (map);
}
