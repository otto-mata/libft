/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_realloc.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/18 15:31:43 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	*gc_realloc(void *mem, size_t old_sz, size_t new_sz)
{
	t_block		*block;
	void		*nmem;
	size_t		sz;

	nmem = gc_malloc(new_sz);
	if (!nmem)
		return (0);
	if (!mem)
		return (nmem);
	block = gc_addr_find(mem);
	if (!block)
		return (0);
	sz = otto_min(new_sz, old_sz);
	while (sz--)
		((unsigned char *)nmem)[sz] = ((unsigned char *)mem)[sz];
	gc_delblock(block);
	return (nmem);
}
