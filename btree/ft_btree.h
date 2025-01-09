/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_btree.h                                           ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/04 21:05:37 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/04 22:43:23 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H
# include <stdlib.h>

typedef struct s_btree	t_btree;

struct					s_btree
{
	t_btree				*left;
	t_btree				*right;
	void				*item;
};
void					btree_apply_prefix(t_btree *root,
							void (*apply)(void *));
void					btree_apply_infix(t_btree *root, void (*apply)(void *));
void					btree_apply_suffix(t_btree *root,
							void (*apply)(void *));
t_btree					*btree_create_node(void *item);
int						btree_level_count(t_btree *root);
t_btree					*btree_search_node(t_btree *root, void *data_ref,
							int (*cmpf)(void *, void *));
void					btree_insert_data(t_btree **root, void *item,
							int (*cmpf)(void *, void *));
void					btree_apply_by_level(t_btree *root,
							void (*applyf)(void *item, int current_level,
								int is_first_elem));
#endif
