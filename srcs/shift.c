/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:35:51 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/07 22:37:44 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	shift_up(t_vars *vars);
static void	shift_down(t_vars *vars);
static void	shift_left(t_vars *vars);
static void	shift_right(t_vars *vars);

void	shift(int key, t_vars *vars)
{
	if (key == ARROW_UP)
		shift_up(vars);
	if (key == ARROW_DOWN)
		shift_down(vars);
	if (key == ARROW_LEFT)
		shift_left(vars);
	if (key == ARROW_RIGHT)
		shift_right(vars);
}

static void	shift_up(t_vars *vars)
{
	vars->points.y_max -= 0.1;
	vars->points.y_min -= 0.1;
	render_frame(vars);
}

static void	shift_down(t_vars *vars)
{
	vars->points.y_max += 0.1;
	vars->points.y_min += 0.1;
	render_frame(vars);
}

static void	shift_left(t_vars *vars)
{
	vars->points.x_max -= 0.1;
	vars->points.x_min -= 0.1;
	render_frame(vars);
}

static void	shift_right(t_vars *vars)
{
	vars->points.x_max += 0.1;
	vars->points.x_min += 0.1;
	render_frame(vars);
}
