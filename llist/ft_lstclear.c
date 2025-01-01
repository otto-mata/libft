/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:40:55 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 20:19:15 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*iter;
	t_list	*next;

	if (!lst || !del)
		return ;
	iter = *lst;
	while (iter)
	{
		next = iter->next;
		del(iter->content);
		free(iter);
		iter = next;
	}
	*lst = 0;
}
