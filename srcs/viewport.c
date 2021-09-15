/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:57:03 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/15 02:09:06 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse_hook(int keycode, int x, int y);

void	window_to_viewport(int x, int y, t_fractol *fractol, t_mlx *mlx)
{
	double	scale_x;
	double	scale_y;

	mlx_mouse_hook(mlx->win, mouse_hook, &mlx);
	scale_x = (fractol->x_max - fractol->x_min) / WIDTH;
	scale_y = (fractol->y_max - fractol->y_min) / HEIGHT;
	fractol->x_view = fractol->x_min + x * scale_x;
	fractol->y_view = fractol->y_min + y * scale_y;
}

static int	mouse_hook(int keycode, int x, int y)
{
	if (keycode == 4 || keycode == 5)
		printf("Key Pressed: %d, x: %d, y: %d\n", keycode, x, y);
	return (0);
}
