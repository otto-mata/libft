/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   init.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 16:08:35 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/12 09:15:00 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "va_internals.h"
#include "inc/vecarr.h"

static void	va_init(t_vecarr *v)
{
	v->len = 0;
	v->allocd = 0;
	v->step = 2;
	v->data = NULL;
	v->join = &va_join;
	v->all = &va_all;
	v->delete = &va_delete;
	v->pop = &va_pop;
	v->push = &va_push;
	v->some = &va_some;
	v->find_index = &va_find_index;
	v->find_last_index = &va_find_last_index;
	v->sum = &va_sum;
	v->filter = &va_filter;
	v->map = &va_map;
	v->new = &va_new;
	v->reverse = &va_reverse;
	v->slice = &va_slice;
	v->find_last = &va_find_last;
	v->find = &va_find;
	v->clear = &va_clear;
	v->destroy = &va_destroy;
}

t_vecarr	*va_new(void)
{
	t_vecarr	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	va_init(new);
	return (new);
}
