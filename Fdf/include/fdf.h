/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:28:05 by wwatkins          #+#    #+#             */
/*   Updated: 2015/12/22 19:46:27 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# include <stdio.h> // TEMPORARY

# define ABS(x) (x < 0 ? -x : x)
# define TAB_SIZE 4096 // UGLY AS FUCK

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_env
{
	t_point		**pts;
	t_point		move;
	void		*mlx;
	void		*win;
	int			gw;
	int			gh;
	int			color;
}				t_env;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

int				**ft_read(t_env *e, const char *argv);
void			ft_tabassign(t_env e, int **tab, const char *line);
void			ft_maperror(const char *line);
void			ft_error(int err);

void			ft_core(t_env *e, int **tab);
void			ft_assigncoor(t_env *e, int **tab);
void			ft_drawline(t_env e, t_point p, t_point p1);
t_point			ft_point(int x, int y);

#endif