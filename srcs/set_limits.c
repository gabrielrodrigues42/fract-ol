/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:40:03 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/24 16:17:50 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_limits(t_fractol *fractol, t_points *points)
{
	if (ft_strcmp(fractol->set, "mandelbrot") == 0
		|| ft_strcmp(fractol->set, "burningship") == 0)
	{
		points->x_max = 1.0;
		points->x_min = -2.5;
		points->y_max = 1.1;
		points->y_min = -1.1;
	}
	if (ft_strcmp(fractol->set, "julia") == 0)
	{
		points->x_max = 2.0;
		points->x_min = -2.0;
		points->y_max = 1.2;
		points->y_min = -1.2;
	}
}
