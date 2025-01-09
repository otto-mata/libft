/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   btree_level_count.c                                  ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/04 21:50:41 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/04 22:09:27 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	btree_level_count(t_btree *root)
{
	int	count;

	count = 0;
	if (root == 0)
		return (0);
	if (root->left)
		count = ft_max(count, btree_level_count(root->left));
	if (root->right)
		count = ft_max(count, btree_level_count(root->right));
	return (count + 1);
}
