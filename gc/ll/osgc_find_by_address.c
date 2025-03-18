/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_find_by_address.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:06:20 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/25 10:07:47 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

t_block	*osgc_find_by_address(void *addr)
{
	t_gc	*gc;
	t_block	*block;

	gc = osgc_instance();
	if (!gc)
		return (0);
	if (!gc->blocks)
		return (0);
	block = gc->blocks;
	while (block)
	{
		if ((unsigned long)block->mem == (unsigned long)addr)
			return (block);
		block = block->next;
	}
	return (0);
}
