/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   lock.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/18 11:10:34 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 11:11:40 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_lock(t_stack *s)
{
	if (!s)
		return (1);
	if (s->locked)
		return (-1);
	s->locked = 1;
}
