/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:45:58 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/12 15:23:07 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;

	map = ft_calloc(1, sizeof(t_list));
	if (!map)
		return (0);
	while (lst)
	{
		map->content = f(lst->content);
		lst = lst->next;
		map->next = ft_calloc(1, sizeof(t_list));
		if (!(map->next))
		{
			del(map->content);
			return (0);
		}
		map = map->next;
	}
	return (map);
}
