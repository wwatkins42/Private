/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:36:17 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/10 10:09:16 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_light(t_env *e)
{
	e->ray.pos = e->lgt.pos;
	e->ray.dir = vec3_sub(e->ray.hit, e->lgt.pos);
	vec3_normalize(&e->ray.dir);
}

void	set_shadows(t_env *e, t_obj *obj, double *tmin, double *t)
{
	*tmin = INFINITY;
	if (ray_intersect(e, tmin, t) != obj)
		obj->color = vec3_fmul(obj->color, 0.5);
}

void	set_lambertian_shading(t_env *e, t_obj *obj)
{
	double	shade;
	double	ambient;
	double	diffuse;
	t_vec3	color;

	ambient = 0.5;
	diffuse = 1 - ambient;
	shade = vec3_dot(e->ray.dir, obj->normal);
	if (shade < 0)
		shade = 0.0;
	color = vec3_fmul(e->lgt.color, ambient + diffuse * shade);
	vec3_clamp(&color, 0.0, 1.0);
	obj->color = color;
}

void	set_normal(t_env *e, t_obj *obj)
{
	obj->normal = vec3_sub(obj->pos, obj->dir); // incorrect
	if (obj->type == SPHERE)
		obj->normal = vec3_sub(obj->pos, e->ray.hit);
	if (obj->type == CYLINDER || obj->type == CONE)
		obj->normal = vec3(obj->pos.x - e->ray.hit.x, 0.0,
						obj->pos.z - e->ray.hit.z);
	vec3_normalize(&obj->normal);
}
