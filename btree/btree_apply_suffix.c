/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   btree_apply_suffix.c                                 ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/04 21:22:23 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/04 21:46:02 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*apply)(void *))
{
	if (!root || !apply)
		return ;
	btree_apply_prefix(root->left, apply);
	btree_apply_prefix(root->right, apply);
	apply(root->item);
}
