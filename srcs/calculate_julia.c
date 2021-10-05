/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_julia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 01:05:37 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/02 14:57:32 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(t_vars *vars)
{
	double	x;
	double	y;
	double	x2;
	double	y2;

	x = vars->points.x_view;
	y = vars->points.y_view;
	x2 = vars->points.x_view * vars->points.x_view;
	y2 = vars->points.y_view * vars->points.y_view;
	vars->points.iter = 0;
	while (x2 + y2 <= 4 && vars->points.iter < MAX_ITER)
	{
		y = 2 * x * y + vars->points.imaginary;
		x = x2 - y2 + vars->points.real;
		x2 = x * x;
		y2 = y * y;
		vars->points.iter++;
	}
}
