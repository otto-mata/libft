/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_newblock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:28:13 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/25 10:07:25 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

t_block	*osgc_newblock(void *mem)
{
	t_block	*node;

	node = malloc(sizeof(t_block));
	if (!node)
		return (0);
	node->mem = mem;
	node->next = 0;
	return (node);
}
