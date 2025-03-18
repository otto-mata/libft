/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sum.c                                                ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 16:22:34 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/12 09:15:00 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "va_internals.h"
#include "inc/vecarr.h"

long	va_sum(t_vecarr *v)
{
	long	val;
	long	res;
	long	curr;
	long	i;

	i = 0;
	res = 0;
	while (i < v->len)
	{
		curr = *(long *)v->data[i];
		val = res;
		if (__builtin_saddl_overflow(val, curr, &res))
			__va_warn("warn - va_sum: overflow");
		i++;
	}
	return (res);
}
