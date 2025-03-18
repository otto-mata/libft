/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_blocksz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:32:16 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/25 13:59:10 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

int	osgc_blocksz(void)
{
	int		i;
	t_gc	*gc;
	t_block	*iter;

	gc = osgc_instance();
	i = 0;
	iter = gc->blocks;
	while (iter)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}
