/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   vec3_mult_scalar.c                                   ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/12/01 01:46:29 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 06:03:32 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	*vec3_mult_scalar(t_vec3 *u, double t)
{
	t_vec3	*w;

	w = malloc(sizeof(t_vec3));
	if (!w)
		return (0);
	w->x = u->x * t;
	w->y = u->y * t;
	w->z = u->z * t;
	return (w);
}
