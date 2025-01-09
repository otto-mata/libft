/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   btree_create_node.c                                  ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/04 21:24:42 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/04 21:46:03 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	if (!node)
		return (0);
	node->left = 0;
	node->right = 0;
	node->item = item;
	return (node);
}
