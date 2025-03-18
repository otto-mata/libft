/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stack.c                                              ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/18 11:00:13 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 11:45:03 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*alloc_stack(void)
{
	t_stack	*s;

	s = mm_malloc(sizeof(*s));
	if (!s)
		return (0);
	s->content = mm_malloc(sizeof(void *));
	if (!s->content)
	{
		mm_free(s);
		return (0);
	}
	s->content[0] = mm_malloc(sizeof(void *));
	if (!s->content[0])
	{
		mm_free(s->content);
		mm_free(s);
		return (0);
	}
	s->bp = s->content[0];
	s->sp = s->bp;
	s->top = stack_top(s);
	s->maxsize = 1;
	s->locked = 0;
	return (s);
}
