/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:40:03 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/05 21:40:50 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color(t_vars *vars)
{
	vars->color = &blue;
}

void	set_limits(t_vars *vars)
{
	if (ft_strcmp(vars->set, "mandelbrot") == 0
		|| ft_strcmp(vars->set, "burningship") == 0)
	{
		vars->points.x_max = 1.0;
		vars->points.x_min = -2.5;
		vars->points.y_max = 1.1;
		vars->points.y_min = -1.1;
	}
	if (ft_strcmp(vars->set, "julia") == 0)
	{
		vars->points.x_max = 2.0;
		vars->points.x_min = -2.0;
		vars->points.y_max = 1.2;
		vars->points.y_min = -1.2;
	}
}
