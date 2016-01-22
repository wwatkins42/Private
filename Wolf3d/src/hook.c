/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:06:26 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/22 12:28:46 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float	get_velocity(t_env *e)
{
	float			vel = 0;
	static float	acc = 0;
	static int		dec = 0;

	vel = VEL * acc;
	acc += 0.075;
	if (dec && !e->key.w && acc > 0)
		acc = 0;
	acc > 1 ? acc = 1 : 0;
	acc < 0 ? acc = 0 : 0;

	if (dec && acc == 0)
		dec = 0;
	else if (!dec && acc > 0)
		dec = e->key.w;

	printf("acc: %f\n", acc);
	return (vel);
}

int		loop_hook(t_env *e)
{
	if (e->key.a)
	{
		vec2_rotate(&e->cam.dir, -3.5);
		vec2_rotate(&e->cam.pln, -3.5);
	}
	if (e->key.d)
	{
		vec2_rotate(&e->cam.dir, 3.5);
		vec2_rotate(&e->cam.pln, 3.5);
	}
	if (e->key.w)
		e->map.pos = vec2_add(e->map.pos, vec2_scale(e->cam.dir, 0.075));
	if (e->key.s)
		e->map.pos = vec2_sub(e->map.pos, vec2_scale(e->cam.dir, 0.075));
	expose_hook(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.adr);
	img_init(e);
	raycast(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.adr, 0, 0);
	return (0);
}

int		key_pressed(int keycode, t_env *e)
{
	keycode == 53 ? exit(0) : 0;
	keycode == 13 || keycode == 126 ? e->key.w = 1 : 0;
	keycode == 1 || keycode == 125 ? e->key.s = 1 : 0;
	keycode == 0 || keycode == 123 ? e->key.a = 1 : 0;
	keycode == 2 || keycode == 124 ? e->key.d = 1 : 0;
	return (0);
}

int		key_released(int keycode, t_env *e)
{
	keycode == 13 || keycode == 126 ? e->key.w = 0 : 0;
	keycode == 1 || keycode == 125 ? e->key.s = 0 : 0;
	keycode == 0 || keycode == 123 ? e->key.a = 0 : 0;
	keycode == 2 || keycode == 124 ? e->key.d = 0 : 0;
	return (0);
}
