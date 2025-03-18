/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   some.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 18:06:18 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 10:52:38 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "inc/gc_vecarr.h"

int	va_some(t_vecarr *v, int (*test)(void *))
{
	long	i;

	if (!v || !test)
		return (0);
	i = 0;
	while (i < v->len)
		if (test(v->data[i++]))
			return (1);
	return (0);
}
