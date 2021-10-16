/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:35:51 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/15 21:37:27 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	shift_up(t_vars *vars, double delta);
static void	shift_down(t_vars *vars, double delta);
static void	shift_left(t_vars *vars, double delta);
static void	shift_right(t_vars *vars, double delta);

void	shift(int key, t_vars *vars)
{
	double	delta;

	delta = (vars->points.x_max - vars->points.x_min);
	if (key == ARROW_UP)
		shift_up(vars, delta);
	if (key == ARROW_DOWN)
		shift_down(vars, delta);
	if (key == ARROW_LEFT)
		shift_left(vars, delta);
	if (key == ARROW_RIGHT)
		shift_right(vars, delta);
}

static void	shift_up(t_vars *vars, double delta)
{
	vars->points.y_max -= delta * SHIFT_FACTOR;
	vars->points.y_min -= delta * SHIFT_FACTOR;
	render_frame(vars);
}

static void	shift_down(t_vars *vars, double delta)
{
	vars->points.y_max += delta * SHIFT_FACTOR;
	vars->points.y_min += delta * SHIFT_FACTOR;
	render_frame(vars);
}

static void	shift_left(t_vars *vars, double delta)
{
	vars->points.x_max -= delta * SHIFT_FACTOR;
	vars->points.x_min -= delta * SHIFT_FACTOR;
	render_frame(vars);
}

static void	shift_right(t_vars *vars, double delta)
{
	vars->points.x_max += delta * SHIFT_FACTOR;
	vars->points.x_min += delta * SHIFT_FACTOR;
	render_frame(vars);
}
