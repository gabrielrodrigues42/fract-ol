/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:54:43 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/24 01:01:29 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_to_viewport(int x, int y, t_points *points)
{
	points->scale_x = (points->x_max - points->x_min) / WIDTH;
	points->scale_y = (points->y_max - points->y_min) / HEIGHT;
	points->x_view = points->x_min + x * points->scale_x;
	points->y_view = points->y_min + y * points->scale_y;
}
