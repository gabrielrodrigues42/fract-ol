/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:35:51 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/26 11:53:40 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	shift_up(t_vars *vars, double delta);
static void	shift_down(t_vars *vars, double delta);
static void	shift_left(t_vars *vars, double delta);
static void	shift_right(t_vars *vars, double delta);

void	shift(int key, t_vars *vars)
{
	double	x_delta;
	double	y_delta;

	x_delta = (vars->points.x_max - vars->points.x_min);
	y_delta = (vars->points.y_max - vars->points.y_min);
	if (key == ARROW_UP)
		shift_up(vars, y_delta);
	if (key == ARROW_DOWN)
		shift_down(vars, y_delta);
	if (key == ARROW_LEFT)
		shift_left(vars, x_delta);
	if (key == ARROW_RIGHT)
		shift_right(vars, x_delta);
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
