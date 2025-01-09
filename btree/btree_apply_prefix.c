/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   btree_apply_prefix.c                                 ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/04 21:22:23 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/04 21:46:01 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*apply)(void *))
{
	if (!root || !apply)
		return ;
	apply(root->item);
	btree_apply_prefix(root->left, apply);
	btree_apply_prefix(root->right, apply);
}
