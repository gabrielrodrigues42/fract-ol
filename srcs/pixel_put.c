/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:49:23 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/25 13:34:49 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color(t_vars *vars);

void	pixel_put(int x, int y, t_vars *vars)
{
	char	*dst;

	dst = vars->mlx.addr + (y * vars->mlx.len + x * (vars->mlx.bpp / 8));
	*(int *)dst = color(vars);
}

static int	color(t_vars *vars)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		rgb;

	t = (double)vars->points.iter / MAX_ITER;
	r = 9 * (1 - t) * t * t * t * 255;
	g = 15 * (1 - t) * (1 - t) * t * t * 255;
	b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	rgb = b << 16 | g << 8 | r;
	return (rgb);
}
