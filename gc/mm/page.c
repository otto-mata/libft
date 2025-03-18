/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottomata <ottomata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:13:23 by ottomata          #+#    #+#             */
/*   Updated: 2025/03/09 01:47:49 by ottomata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_manager.h"

static int	__new_memory_page_node(t_mpn **out)
{
	t_mpn	*val;

	if (!out)
		return (1);
	val = malloc(sizeof(t_mpn));
	if (!val)
		return (1);
	ft_bzero(val, sizeof(t_mpn));
	*out = val;
	return (0);
}

static int	__new_memory_page(size_t page_size, t_mpn *node)
{
	t_mpc	*chunk;

	if (!node)
		return (1);
	node->pages[node->len].mem = malloc(page_size);
	if (!node->pages[node->len].mem)
		return (1);
	ft_bzero(node->pages[node->len].mem, page_size);
	node->pages[node->len].sz = page_size;
	chunk = get_first_block_in_page(&node->pages[node->len]);
	chunk->x = 0;
	chunk->sz = page_size - sizeof(t_mpc) * 2;
	node->len++;
	return (0);
}

int	new_memory_page(t_mm *mm, size_t page_size)
{
	t_mpn	*node;

	page_size = pow_2_up_to_exp(page_size, PAGE_POW_2);
	if (!mm->pnodes && __new_memory_page_node(&mm->pnodes))
		return (1);
	node = mm->pnodes;
	while (node && node->len == PAGES_PER_NODE)
	{
		if (!node->fwd && __new_memory_page_node(&node->fwd))
			return (1);
		node = node->fwd;
	}
	return (__new_memory_page(page_size, node));
}
