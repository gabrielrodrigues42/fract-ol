/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_burningship.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 01:06:09 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/24 19:42:30 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_burningship(t_points *points)
{
	double	x;
	double	y;
	double	x2;
	double	y2;

	x = 0.0;
	y = 0.0;
	x2 = 0.0;
	y2 = 0.0;
	points->iter = 0;
	while (x2 + y2 <= 4 && points->iter < MAX_ITER)
	{
		y = fabs(2 * x * y) + points->y_view;
		x = x2 - y2 + points->x_view;
		x2 = x * x;
		y2 = y * y;
		points->iter++;
	}
}
