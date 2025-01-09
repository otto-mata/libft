/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   vec3_new.c                                           ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/12/01 01:57:18 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 06:03:34 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	*vec3_new(double x, double y, double z)
{
	t_vec3	*v;

	v = malloc(sizeof(t_vec3));
	if (!v)
		return (0);
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}
