/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   filter.c                                             ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 16:09:50 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/12 09:15:00 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "va_internals.h"
#include "inc/vecarr.h"

t_vecarr	*va_filter(t_vecarr *v, int (*test)(void *))
{
	long		i;
	t_vecarr	*match;

	match = malloc(sizeof(*match));
	if (!match)
		return (0);
	i = 0;
	while (i < v->len)
	{
		if (test(v->data[i]))
			va_push(match, v->data[i]);
		i++;
	}
	return (match);
}
