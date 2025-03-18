/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   block.c                                              ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/09 00:58:08 by ottomata             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/11 14:26:36 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "mem_manager.h"

t_mpc	*get_first_block_in_page(t_mp *mem_page)
{
	t_mpc	*chunk;

	if (!mem_page)
		return (0);
	chunk = mem_page->mem;
	return (chunk);
}

t_mpc	*get_next_block_in_page(t_mpc *chunk, int find_zero)
{
	t_mpc	*next;

	if (!chunk)
		return (0);
	next = (void *)(chunk) + sizeof(t_mpc) + chunk->sz;
	if (!find_zero && next->sz == 0)
	{
		return (0);
	}
	return (next);
}

t_mpc	*fragment_block(t_mpc *chunk, size_t sz)
{
	size_t	remaining;
	t_mpc	*ac_next;

	if (!chunk)
		return (0);
	if (chunk->sz > sz + sizeof(t_mpc) + (2 << PAGE_ALIGN))
	{
		remaining = chunk->sz - sz - sizeof(t_mpc);
		chunk->sz = sz;
		ac_next = get_next_block_in_page(chunk, 1);
		ac_next->x = 0;
		ac_next->sz = remaining;
	}
	return (chunk);
}

static int	__valid_block(size_t size, t_mpc **infop)
{
	if (!(*infop)->x && (*infop)->sz >= size)
	{
		*infop = fragment_block(*infop, size);
		return (1);
	}
	*infop = get_next_block_in_page(*infop, 0);
	return (0);
}

t_mpc	*find_chunk_of_size(t_mm *mm, size_t sz)
{
	t_mpn	*node;
	size_t	idx;
	t_mpc	*mpc;

	node = mm->pnodes;
	while (node)
	{
		idx = 0;
		while (idx < node->len)
		{
			mpc = get_first_block_in_page(&node->pages[idx++]);
			while (mpc)
				if (__valid_block(sz, &mpc))
					return (mpc);
		}
		node = node->fwd;
	}
	return (0);
}
