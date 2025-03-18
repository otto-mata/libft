/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_addblock_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:35:30 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/25 10:07:47 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

t_block	*osgc_addblock_back(t_block *new)
{
	t_block	*tmp;
	t_gc	*gc;

	gc = osgc_instance();
	if (!(gc))
		return (0);
	if (!(gc->blocks))
	{
		gc->blocks = new;
		return (gc->blocks);
	}
	tmp = gc->blocks;
	while (tmp)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	tmp->next = new;
	return (gc->blocks);
}
