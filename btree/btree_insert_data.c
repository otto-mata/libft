/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   btree_insert_data.c                                  ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/04 21:34:01 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/04 22:09:02 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *,
			void *))
{
	t_btree	*walker;

	if (!(*root))
	{
		*root = btree_create_node(item);
		return ;
	}
	walker = *root;
	if (cmpf(item, walker->item) < 0)
	{
		if (walker->left)
			btree_insert_data(&walker, item, cmpf);
		else
			walker->left = btree_create_node(item);
	}
	else
	{
		if (walker->right)
			btree_insert_data(&walker, item, cmpf);
		else
			walker->right = btree_create_node(item);
	}
}
