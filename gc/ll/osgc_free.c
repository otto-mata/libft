/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:53:29 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/25 11:54:47 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

void	osgc_free(void *mem)
{
	t_block *const	block = osgc_find_by_address(mem);

	if (!block)
		return ;
	osgc_delblock(block);
}
