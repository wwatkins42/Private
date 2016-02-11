/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 12:13:56 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/11 12:13:57 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_camera(t_env *e)
{
	e->cam.pos = (t_vec3) { 0.0, 0.0, 0.0 };
	e->cam.dir = (t_vec3) { 0.0, 0.0, 1.0 };
	e->cam.fov = 60;
}

void	init_object(t_obj *obj)
{
	obj->type = SPHERE;
	obj->pos = (t_vec3) { 0.0, 0.0, 0.0 };
	obj->dir = (t_vec3) { 0.0, 0.0, 0.0 };
	obj->scale = 1.0;
}

void	init_material(t_mat *mat)
{
	mat->color = (t_vec3) { 0.1, 0.1, 0.1 };
	mat->ambient = 0.0;
	mat->diffuse = 0.0;
	mat->specular = 0.0;
	mat->shininess = 0.0;
}

void	init_light(t_lgt *light)
{
	light->pos = (t_vec3) { 0.0, 0.0, 0.0 };
	light->color = (t_vec3) { 0.0, 0.0, 0.0 };
}
