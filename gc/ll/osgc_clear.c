/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:40:55 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/25 10:07:47 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

void	*osgc_clear(void)
{
	t_block	*iter;
	t_block	*tmp;
	t_gc	*gc;

	gc = osgc_instance();
	if (!gc)
		return (0);
	iter = (gc)->blocks;
	while (iter)
	{
		free(iter->mem);
		tmp = iter->next;
		free(iter);
		iter = tmp;
	}
	free(gc);
	return (0);
}
