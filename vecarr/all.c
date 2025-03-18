/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   all.c                                                ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 18:06:18 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/12 09:15:00 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "inc/vecarr.h"

int	va_all(t_vecarr *v, int (*test)(void *))
{
	long	i;

	if (!v || !test)
		return (0);
	i = 0;
	while (i < v->len)
		if (!test(v->data[i++]))
			return (0);
	return (1);
}
