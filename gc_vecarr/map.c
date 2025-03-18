/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   map.c                                                ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 17:12:24 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 10:52:38 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gcva_internals.h"
#include "inc/gc_vecarr.h"

t_vecarr	*va_map(t_vecarr *orig, void *(*map_fn)(void *))
{
	t_vecarr	*new;
	long		i;

	if (!orig || !map_fn)
		return (0);
	new = va_new();
	if (!new)
		return (0);
	i = 0;
	while (i < orig->len)
		va_push(new, map_fn(orig->data[i++]));
	return (new);
}
