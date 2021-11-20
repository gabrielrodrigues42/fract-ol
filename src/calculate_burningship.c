/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_burningship.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 01:06:09 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/25 12:28:52 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_burningship(t_vars *vars)
{
	double	x;
	double	y;
	double	x2;
	double	y2;

	x = 0.0;
	y = 0.0;
	x2 = 0.0;
	y2 = 0.0;
	vars->points.iter = 0;
	while (x2 + y2 <= 4 && vars->points.iter < MAX_ITER)
	{
		y = fabs(2 * x * y) + vars->points.y_view;
		x = x2 - y2 + vars->points.x_view;
		x2 = x * x;
		y2 = y * y;
		vars->points.iter++;
	}
}
