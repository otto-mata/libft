/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   reverse.c                                            ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 17:36:42 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 10:52:38 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gcva_internals.h"
#include "inc/gc_vecarr.h"

t_vecarr	*va_reverse(t_vecarr *v)
{
	t_vecarr	*reversed;
	long		i;

	if (!v)
		return (0);
	reversed = va_new();
	if (!reversed)
		return (0);
	i = v->len - 1;
	while (i >= 0)
		va_push(reversed, v->data[i--]);
	return (reversed);
}
