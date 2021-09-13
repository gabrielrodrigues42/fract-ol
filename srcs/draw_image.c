/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:45:21 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/12 20:27:29 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color(t_fractol *fractol);

void	my_mlx_pixel_put(int x, int y, t_fractol *fractol, t_mlx *mlx)
{
	char	*dst;

	dst = mlx->addr + y * mlx->line_len + x * mlx->bpp / 8;
	*(int *)dst = color(fractol);
}

static int	color(t_fractol *fractol)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		rgb;

	t = fractol->iter / (double)MAX_ITER;
	r = 9 * (1 - t) * t * t * t * 255;
	g = 15 * (1 - t) * (1 - t) * t * t * 255;
	b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	rgb = r << 16 | g << 8 | b;
	return (rgb);
}
