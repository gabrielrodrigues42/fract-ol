/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:40:03 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/19 19:38:01 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_default_julia(t_vars *vars)
{
	vars->points.real = 0.0;
	vars->points.imaginary = 0.0;
}

void	set_default_color(t_vars *vars)
{
	vars->colors.index = 0;
	vars->fn_color = &blue;
}

void	set_default_limits(t_vars *vars)
{
	if (ft_strcmp(vars->set, "mandelbrot") == 0)
	{
		vars->points.x_max = 1.0;
		vars->points.x_min = -2.5;
		vars->points.y_max = 1.5;
		vars->points.y_min = -1.5;
	}
	if (ft_strcmp(vars->set, "burning-ship") == 0)
	{
		vars->points.x_max = 2.0;
		vars->points.x_min = -3.0;
		vars->points.y_max = 1.0;
		vars->points.y_min = -2.0;
	}
	if (ft_strcmp(vars->set, "julia") == 0)
	{
		vars->points.x_max = 2.0;
		vars->points.x_min = -2.0;
		vars->points.y_max = 1.5;
		vars->points.y_min = -1.5;
	}
}
