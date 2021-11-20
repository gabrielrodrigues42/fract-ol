/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_to_viewport.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:54:43 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/07 01:09:10 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_to_viewport(int x, int y, t_vars *vars)
{
	double	x_scale;
	double	y_scale;

	x_scale = (vars->points.x_max - vars->points.x_min) / WIDTH;
	y_scale = (vars->points.y_max - vars->points.y_min) / HEIGHT;
	vars->points.x_view = vars->points.x_min + x * x_scale;
	vars->points.y_view = vars->points.y_min + y * y_scale;
}
