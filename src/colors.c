/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:56:56 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/19 19:40:17 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color(t_vars *vars)
{
	double	t;
	int		rgb;

	t = (double)vars->points.iter / MAX_ITER;
	vars->colors.r = 9 * (1 - t) * t * t * t * 255;
	vars->colors.g = 15 * (1 - t) * (1 - t) * t * t * 255;
	vars->colors.b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	rgb = vars->fn_color(vars);
	return (rgb);
}

void	change_color(int index, t_vars *vars)
{
	int	(*selector[3])(t_vars *);

	selector[0] = &blue;
	selector[1] = &red;
	selector[2] = &green;
	vars->fn_color = selector[index];
	render_frame(vars);
}

int	red(t_vars *vars)
{
	return (vars->colors.b << 16 | vars->colors.g << 8 | vars->colors.r);
}

int	green(t_vars *vars)
{
	return (vars->colors.r << 16 | vars->colors.b << 8 | vars->colors.g);
}

int	blue(t_vars *vars)
{
	return (vars->colors.r << 16 | vars->colors.g << 8 | vars->colors.b);
}
