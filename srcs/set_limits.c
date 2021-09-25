/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:40:03 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/25 12:23:46 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_limits(t_vars *vars)
{
	if (ft_strcmp(vars->fractol.set, "mandelbrot") == 0
		|| ft_strcmp(vars->fractol.set, "burningship") == 0)
	{
		vars->points.x_max = 1.0;
		vars->points.x_min = -2.5;
		vars->points.y_max = 1.1;
		vars->points.y_min = -1.1;
	}
	if (ft_strcmp(vars->fractol.set, "julia") == 0)
	{
		vars->points.x_max = 2.0;
		vars->points.x_min = -2.0;
		vars->points.y_max = 1.2;
		vars->points.y_min = -1.2;
	}
}
