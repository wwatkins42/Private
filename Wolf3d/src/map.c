/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 09:34:44 by wwatkins          #+#    #+#             */
/*   Updated: 2016/01/21 17:17:29 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	map_init(t_env *e)
{
	e->map.size = 64;
	map_parse(e);
}

void	map_parse(t_env *e)
{
	int		j;
	int		fd;
	char	*line;

	j = 0;
	error((fd = open(e->arg.map, O_RDWR)));
	get_next_line(fd, &line);
	e->map.w = ft_atoi(line);
	get_next_line(fd, &line);
	e->map.h = ft_atoi(line);
	error((int)(e->map.map = (int**)malloc(sizeof(int*) * e->map.h)));
	while (get_next_line(fd, &line))
	{
		map_assign(e, line, j);
		free(line);
		j++;
	}
	error((close(fd) + 1));
}

void	map_assign(t_env *e, const char *line, int j)
{
	int		i;
	char	**split;

	i = -1;
	split = ft_strsplit(line, ' ');
	while (split[++i] != NULL)
	{
		error((int)(e->map.map[j] = (int*)malloc(sizeof(int) * e->map.w)));
		e->map.map[j][i] = ft_atoi(split[i]);
		free(split[i]);
	}
	free(split);
}

void	map_coor(t_env *e)
{
	e->map.pos = vec2_mul(e->cam.pos,
	vec2(e->map.w / (float)e->win_w, e->map.h / (float)e->win_h));
}
