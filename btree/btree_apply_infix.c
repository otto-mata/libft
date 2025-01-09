/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   btree_apply_infix.c                                  ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/04 21:22:23 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/04 21:46:00 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*apply)(void *))
{
	if (!root || !apply)
		return ;
	btree_apply_infix(root->left, apply);
	apply(root->item);
	btree_apply_infix(root->right, apply);
}
