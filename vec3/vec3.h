/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   vec3.h                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/12/01 01:30:51 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 06:03:48 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H
# include <math.h>
# include <stdlib.h>

typedef struct s_vec3	t_vec3;
typedef t_vec3			t_point3;

struct					s_vec3
{
	double				x;
	double				y;
	double				z;
};

t_vec3					*vec3_new(double x, double y, double z);
void					vec3_ip_add(t_vec3 *to, t_vec3 *v);
void					vec3_ip_mult(t_vec3 *v, double t);
void					vec3_ip_div(t_vec3 *v, double t);
void					vec3_ip_sub(t_vec3 *to, t_vec3 *v);
double					vec3_sqrd_len(t_vec3 *v);
double					vec3_len(t_vec3 *v);
t_vec3					*vec3_add(t_vec3 *u, t_vec3 *v);
t_vec3					*vec3_sub(t_vec3 *u, t_vec3 *v);
t_vec3					*vec3_mult(t_vec3 *u, t_vec3 *v);
t_vec3					*vec3_mult_scalar(t_vec3 *u, double t);
t_vec3					*vec3_div_scalar(t_vec3 *u, double t);
double					vec3_dot(t_vec3 *u, t_vec3 *v);
t_vec3					*vec3_cross(t_vec3 *u, t_vec3 *v);
t_vec3					*vec3_copy(t_vec3 *v);
t_vec3					*vec3_unit(t_vec3 *v);
#endif