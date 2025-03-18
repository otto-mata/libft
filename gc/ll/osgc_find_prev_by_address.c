/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_find_prev_by_address.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:59:03 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/25 10:07:47 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

t_block	*osgc_find_prev_by_address(void *addr)
{
	t_gc	*gc;
	t_block	*block;

	gc = osgc_instance();
	if (!gc)
		return (0);
	if (!gc->blocks)
		return (0);
	block = gc->blocks;
	while (block && block->next)
	{
		if ((unsigned long)block->next->mem == (unsigned long)addr)
			return (block);
		block = block->next;
	}
	return (0);
}
