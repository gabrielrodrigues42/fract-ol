/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_julia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 01:05:37 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/12 12:27:55 by gandrade         ###   ########.fr       */
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
	x2 = 0;
	y2 = 0;
	vars->points.iter = 0;
	while (x2 + y2 <= 4 && vars->points.iter < MAX_ITER)
	{
		x2 = x * x;
		y2 = y * y;
		y = 2 * x * y + vars->points.imaginary;
		x = x2 - y2 + vars->points.real;
		vars->points.iter++;
	}
}
