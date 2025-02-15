/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_realloc.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/09 05:39:29 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/02/15 12:59:53 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

void	*ft_realloc(void *mem, size_t old_sz, size_t new_sz)
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
