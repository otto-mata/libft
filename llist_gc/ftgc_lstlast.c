/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftgc_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:33:48 by tblochet          #+#    #+#             */
/*   Updated: 2025/01/01 20:19:15 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gcllist.h"

t_gclist	*ftgc_lstlast(t_gclist *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
