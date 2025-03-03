/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ftgc_lstadd_front.c                                  ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/12 14:30:42 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/03 08:25:34 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gcllist.h"

void	ftgc_lstadd_front(t_gclist **lst, t_gclist *new)
{
	new->next = *lst;
	*lst = new;
}
