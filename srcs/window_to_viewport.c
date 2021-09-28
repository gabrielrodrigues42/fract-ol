/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_to_viewport.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:54:43 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/27 23:59:39 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_to_viewport(int x, int y, t_vars *vars)
{
	double	scale_x;
	double	scale_y;

	scale_x = (vars->points.x_max - vars->points.x_min) / WIDTH;
	scale_y = (vars->points.y_max - vars->points.y_min) / HEIGHT;
	vars->points.x_view = vars->points.x_min + x * scale_x;
	vars->points.y_view = vars->points.y_min + y * scale_y;
}
