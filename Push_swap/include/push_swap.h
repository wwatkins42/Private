/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 10:36:15 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/26 14:56:40 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // temporary

# define ABS(x) (x < 0 ? -x : x)

enum { ONE, BOTH };
enum { INC, DEC };

typedef struct	s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_move
{
	char			*name;
	struct s_move	*next;
}				t_move;

typedef struct	s_env
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_end_a;
	t_stack	*stack_end_b;
	t_move	*move;
	t_move	*move_end;
	int		count;
	int		min;
	int		count_min;
	int		m;
}				t_env;

/*
**	main.c
*/

void			check_args(int argc, char **argv);
void			create_stacks(t_env *e, int argc, char **argv);
void			error(int err);

/*
**	resolve.c
*/

int				resolve(t_env *e);
int				sort(t_env *e);
int				bubble_sort(t_env *e);
int				check_sorted(t_stack *stack, int mode);

/*
**	move_swap.c
*/

int				move_swap_a(t_env *e, int move);
int				move_swap_b(t_env *e, int move);
void			move_swap_both(t_env *e);

/*
**	move_push.c
*/

void			move_push_a(t_env *e);
void			move_push_b(t_env *e);

/*
**	move_rotate.c
*/

int				move_rotate_a(t_env *e, int move);
int				move_rotate_b(t_env *e, int move);
void			move_rotate_both(t_env *e);

/*
**	move_reverse_rotate.c
*/

int				move_reverse_rotate_a(t_env *e, int move);
int				move_reverse_rotate_b(t_env *e, int move);
void			move_reverse_rotate_both(t_env *e);

/*
**	utils.c
*/

void			add_move(t_env *e, char *move);
void			disp_moves(t_env *e);
void			disp_stack(t_stack *stack);

#endif
