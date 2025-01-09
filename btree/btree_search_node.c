/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   btree_search_node.c                                  ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/04 21:46:20 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/04 22:43:13 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_search_node(t_btree *root, void *data_ref, int (*cmpf)(void *,
			void *))
{
	t_btree	*match;

	if (!root || !cmpf || !data_ref)
		return (0);
	match = btree_search_node(root->left, data_ref, cmpf);
	if (match)
		return (match);
	if (cmpf(data_ref, root->item) == 0)
		return (root);
	match = btree_search_node(root->right, data_ref, cmpf);
	if (match)
		return (match);
	return (0);
}
