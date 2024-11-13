/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:45:58 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/13 21:06:19 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;

	map = ft_lstnew(f(lst->content));
	if (!map)
		return (0);
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&map, ft_lstnew(f(lst->content)));
		if (ft_lstlast(map) == 0)
			ft_lstclear(&map, del);
		lst = lst->next;
	}
	return (map);
}
