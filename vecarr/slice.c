/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   slice.c                                              ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 17:41:24 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/12 09:15:00 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "va_internals.h"
#include "inc/vecarr.h"

t_vecarr	*va_slice(t_vecarr *v, long begin, long end)
{
	t_vecarr	*slice;
	long		i;

	if (!v)
		return (0);
	if (begin < 0)
		begin = v->len + begin;
	if (end < 0)
		end = v->len + end;
	slice = va_new();
	if (!slice)
		return (0);
	i = begin;
	while (i < end)
		va_push(slice, v->data[i++]);
	return (slice);
}
