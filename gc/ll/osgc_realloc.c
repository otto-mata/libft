/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osgc_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:31:43 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/25 12:51:42 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "osgc.h"

void	*osgc_realloc(void *mem, size_t old_sz, size_t new_sz)
{
	t_block		*block;
	void		*nmem;
	size_t		sz;

	nmem = osgc_malloc(new_sz);
	if (!nmem)
		return (0);
	if (!mem)
		return (nmem);
	block = osgc_find_by_address(mem);
	if (!block)
		return (0);
	sz = otto_min(new_sz, old_sz);
	while (sz--)
		((unsigned char *)nmem)[sz] = ((unsigned char *)mem)[sz];
	osgc_delblock(block);
	return (nmem);
}
