/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:40:55 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/12 15:14:09 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*iter;
	t_list	*tmp;

	iter = *lst;
	while (iter)
	{
		del(iter->content);
		tmp = iter->next;
		free(iter);
		iter = tmp;
	}
	*lst = 0;
}
