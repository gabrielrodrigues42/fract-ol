/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:22:55 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/05 16:02:21 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int x, int y, int scale_direction, t_vars *vars)
{
	t_zoom	zoom;

	zoom.x_ratio = (double)x / WIDTH;
	zoom.y_ratio = (double)y / HEIGHT;
	zoom.x_delta = vars->points.x_max - vars->points.x_min;
	zoom.y_delta = vars->points.y_max - vars->points.y_min;
	if (scale_direction == ZOOM_IN)
	{
		zoom.x_delta2 = (ZOOM_FACTOR * zoom.x_delta) - zoom.x_delta;
		zoom.y_delta2 = (ZOOM_FACTOR * zoom.y_delta) - zoom.y_delta;
	}
	if (scale_direction == ZOOM_OUT)
	{
		zoom.x_delta2 = (1 / ZOOM_FACTOR * zoom.x_delta) - zoom.x_delta;
		zoom.y_delta2 = (1 / ZOOM_FACTOR * zoom.y_delta) - zoom.y_delta;
	}
	vars->points.x_min -= zoom.x_delta2 * zoom.x_ratio;
	vars->points.x_max += zoom.x_delta2 * (1 - zoom.x_ratio);
	vars->points.y_max += zoom.y_delta2 * (1 - zoom.y_ratio);
	vars->points.y_min -= zoom.y_delta2 * zoom.y_ratio;
	render_frame(vars);
}
