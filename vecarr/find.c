/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   find.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 16:13:44 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/12 09:15:00 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "va_internals.h"
#include "inc/vecarr.h"

void	*va_find(t_vecarr *v, int (*test)(void *))
{
	long	i;

	i = 0;
	while (i < v->len)
	{
		if (test(v->data[i]))
			return (v->data[i]);
		i++;
	}
	return (0);
}

long	va_find_index(t_vecarr *v, int (*test)(void *))
{
	long	i;

	i = 0;
	while (i < v->len)
	{
		if (test(v->data[i]))
			return ((long)i);
		i++;
	}
	return (-1);
}

void	*va_find_last(t_vecarr *v, int (*test)(void *))
{
	long	i;

	i = v->len - 1;
	while (i >= 0)
	{
		if (test(v->data[i]))
			return (v->data[i]);
		i--;
	}
	return (0);
}

long	va_find_last_index(t_vecarr *v, int (*test)(void *))
{
	long	i;

	i = v->len - 1;
	while (i >= 0)
	{
		if (test(v->data[i]))
			return (i);
		i--;
	}
	return (-1);
}
