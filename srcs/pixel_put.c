/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:49:23 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/25 01:51:58 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color(t_points *points);

void	pixel_put(int x, int y, t_mlx *mlx, t_points *points)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->len + x * (mlx->bpp / 8));
	*(int *)dst = color(points);
}

static int	color(t_points *points)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		rgb;

	t = (double)points->iter / MAX_ITER;
	r = 9 * (1 - t) * t * t * t * 255;
	g = 15 * (1 - t) * (1 - t) * t * t * 255;
	b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	rgb = b << 16 | g << 8 | r;
	return (rgb);
}
