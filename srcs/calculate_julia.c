/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_julia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 01:05:37 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/24 20:31:28 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(t_points *points)
{
	double	x;
	double	y;
	double	x2;
	double	y2;

	x = points->x_view;
	y = points->y_view;
	x2 = points->x_view * points->x_view;
	y2 = points->y_view * points->y_view;
	points->iter = 0;
	while (x2 + y2 <= 4 && points->iter < MAX_ITER)
	{
		y = 2 * x * y + 0.355;
		x = x2 - y2 + 0.355;
		x2 = x * x;
		y2 = y * y;
		points->iter++;
	}
}
