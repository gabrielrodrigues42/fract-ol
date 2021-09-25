/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:22:55 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/25 17:18:45 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_vars *vars)
{
	double	x_ratio;
	double	y_ratio;
	double	x_delta;
	double	y_delta;
	double	x_delta2;
	double	y_delta2;

	x_ratio = (double)x / WIDTH;
	y_ratio = (double)y / HEIGHT;
	x_delta = vars->points.x_max - vars->points.x_min;
	y_delta = vars->points.y_max - vars->points.y_min;
	x_delta2 = (1.1 * x_delta) - x_delta;
	y_delta2 = (1.1 * y_delta) - y_delta;
	vars->points.x_min -= x_delta2 * x_ratio;
	vars->points.x_max += x_delta2 * (1 - x_ratio);
	vars->points.y_max += y_delta2 * (1 - y_ratio);
	vars->points.y_min -= y_delta2 * y_ratio;
	render_frame(vars);
}

void	zoom_out(int x, int y, t_vars *vars)
{
	double	x_ratio;
	double	y_ratio;
	double	x_delta;
	double	y_delta;
	double	x_delta2;
	double	y_delta2;

	x_ratio = (double)x / WIDTH;
	y_ratio = (double)y / HEIGHT;
	x_delta = vars->points.x_max - vars->points.x_min;
	y_delta = vars->points.y_max - vars->points.y_min;
	x_delta2 = (1 / 1.1 * x_delta) - x_delta;
	y_delta2 = (1 / 1.1 * y_delta) - y_delta;
	vars->points.x_min -= x_delta2 * x_ratio;
	vars->points.x_max += x_delta2 * (1 - x_ratio);
	vars->points.y_max += y_delta2 * (1 - y_ratio);
	vars->points.y_min -= y_delta2 * y_ratio;
	render_frame(vars);
}
