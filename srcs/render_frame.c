/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:42:13 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/24 17:52:09 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_frame(t_fractol *fractol, t_mlx *mlx, t_points *points)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			window_to_viewport(x, y, points);
			fractol->fn(points);
			pixel_put(x, y, mlx, points);
			y++;
		}
		x++;
	}
	put_image_to_window(mlx);
}
