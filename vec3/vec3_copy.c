/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   vec3_copy.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/12/01 02:02:42 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 06:03:27 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	*vec3_copy(t_vec3 *v)
{
	return (vec3_new(v->x, v->y, v->z));
}
