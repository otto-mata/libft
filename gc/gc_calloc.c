/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   gc_calloc.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/18 15:31:29 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	*gc_calloc(size_t nmemb, size_t sz)
{
	void	*mem;

	if (nmemb > 0 && sz > SIZE_MAX / nmemb)
		return (NULL);
	mem = gc_malloc(nmemb * sz);
	if (mem)
		otto_bzero(mem, nmemb * sz);
	return (mem);
}
