/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:56:56 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/05 21:39:27 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color(t_vars *vars)
{
	double	t;
	int		rgb;

	t = (double)pow(log(vars->points.iter), 3) / pow(log(MAX_ITER), 3);
	vars->colors.r = 9 * (1 - t) * t * t * t * 255;
	vars->colors.g = 15 * (1 - t) * (1 - t) * t * t * 255;
	vars->colors.b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	rgb = vars->color(vars);
	return (rgb);
}

void	change_color(int index, t_vars *vars)
{
	int	(*selector[3])(t_vars *);

	selector[0] = &red;
	selector[1] = &blue;
	selector[2] = &green;
	vars->color = selector[index];
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
