/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stack.h                                              ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/18 10:56:57 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 11:44:34 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../gc/mm/mem_manager.h"
# include <stddef.h>

typedef struct s_stack	t_stack;

struct					s_stack
{
	void				**content;
	void				*sp;
	void				*bp;
	size_t				top;
	size_t				maxsize;
	int					locked;
};

int						stack_lock(t_stack *s);
int						stack_set_maxsize(t_stack *s, size_t maxsize);
t_stack					*alloc_stack(void);
size_t					stack_top(t_stack *s);
int						stack_unlock(t_stack *s);

#endif
