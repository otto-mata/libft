/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   set_size.c                                           ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/18 11:07:58 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 11:10:17 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_set_maxsize(t_stack *s, size_t maxsize)
{
	if (maxsize < s->maxsize)
		return (-1);
	s->maxsize = maxsize;
	s->locked = 1;
	return (0);
}
