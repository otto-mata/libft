/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   vec3_cross.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/12/01 01:50:15 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 06:03:28 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	*vec3_cross(t_vec3 *u, t_vec3 *v)
{
	t_vec3	*w;

	w = malloc(sizeof(t_vec3));
	if (!w)
		return (0);
	w->x = (u->y * v->z) - (u->z * v->y);
	w->y = (u->z * v->x) - (u->x * v->z);
	w->z = (u->x * v->y) - (u->y * v->x);
	return (w);
}
