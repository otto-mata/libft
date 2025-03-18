/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   push.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/18 11:42:21 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 11:51:19 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_push(t_stack *s, void *e)
{
	if (stack_top(s) == s->maxsize)
	{
		if (s->locked)
			return (-1);
		else
		{
			s->content = mm_realloc(s->content, (s->maxsize * 2)
					* sizeof(void *));
			if (!s->content)
				return (-2);
		}
	}
	s->content[stack_top(s)] = e;
	s->sp = &(s->content[stack_top(s)]);
	
}
