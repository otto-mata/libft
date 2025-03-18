/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   allocations.c                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/09 00:27:31 by ottomata             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 11:40:34 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "mem_manager.h"

static void	*__realloc(void *p, size_t sz)
{
	t_mpc	*infop;
	t_mpc	*next;

	infop = p - sizeof(t_mpc);
	if (infop->sz >= sz)
		return (p);
	next = get_next_block_in_page(infop, 0);
	if (next && !next->x && infop->sz + next->sz + sizeof(t_mpc) >= sz)
	{
		infop->sz += next->sz + sizeof(t_mpc);
		return (p);
	}
	infop = p - sizeof(t_mpc);
	next = mm_realloc(0, sz);
	ft_memmove(next, p, infop->sz);
	mm_free(p);
	return (next);
}

static void	*__malloc(size_t size)
{
	t_mpc	*infop;
	t_mm	*mm;

	mm = memory_manager();
	infop = find_chunk_of_size(mm, size);
	if (!infop)
	{
		if (new_memory_page(mm, size + sizeof(t_mpc) * 2))
			return (0);
		infop = find_chunk_of_size(mm, size);
		if (!infop)
			return (0);
	}
	infop->x = -1;
	ft_bzero((void *)infop + sizeof(t_mpc), infop->sz);
	return ((void *)infop + sizeof(t_mpc));
}

void	*mm_realloc(void *p, size_t sz)
{
	size_t	rounded_size;

	if (sz > INT32_MAX - sizeof(t_mpc) * 10)
	{
		errno = ENOMEM;
		return (0);
	}
	rounded_size = align_to_2exp(sz, PAGE_ALIGN);
	if (p && !rounded_size)
	{
		mm_free(p);
		return (0);
	}
	if (!p)
		return (__malloc(rounded_size));
	return (__realloc(p, rounded_size));
}

void	*mm_malloc(size_t sz)
{
	return (mm_realloc(0, sz));
}
