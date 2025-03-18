/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   mem_utils.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 17:26:08 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 10:50:48 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gcva_internals.h"

void	*om_realloc(void *mem, size_t old_sz, size_t new_sz)
{
	void	*nmem;
	size_t	sz;

	nmem = malloc(new_sz);
	if (!nmem)
		return (0);
	if (!mem)
		return (nmem);
	if (new_sz < old_sz)
		sz = new_sz;
	else
		sz = old_sz;
	while (sz--)
		((unsigned char *)nmem)[sz] = ((unsigned char *)mem)[sz];
	free(mem);
	return (nmem);
}
