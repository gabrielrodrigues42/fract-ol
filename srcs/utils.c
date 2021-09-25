/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:34:34 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/25 12:05:05 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	put_image_to_window(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return (0);
}

int	destroyer(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	exit(0);
}

int	key_hook(int key, t_mlx *mlx)
{
	if (key == ESC)
		destroyer(mlx);
	printf("Key Pressed: %d\n", key);
	return (0);
}

int	mouse_hook(int key, int x, int y)
{
	if (key == SCROLL_UP || key == SCROLL_DOWN)
		printf("Key Pressed: %d, x: %d, y: %d\n", key, x, y);
	return (0);
}

int	mouse_motion_hook(int x, int y)
{
	printf("x: %d, y: %d\n", x, y);
	return (0);
}
