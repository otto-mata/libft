/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftgc_lstnew.c                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:28:13 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/03 08:24:46 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gcllist.h"

t_gclist	*ftgc_lstnew(void *content)
{
	t_gclist	*node;

	node = gc_calloc(1, sizeof(t_gclist));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}
