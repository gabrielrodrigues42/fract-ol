/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:51:41 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/17 20:42:06 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	destroyer(t_mlx *mlx);
static int	key_hook(int keycode, t_mlx *mlx);

void	mlx_handler(t_fractol *fractol)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, fractol->set);
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.endian);
	fractol->f(fractol, &mlx);
	mlx_hook(mlx.win, 17, 1L << 0, destroyer, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
}

static int	destroyer(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}

static int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		destroyer(mlx);
	printf("Key Pressed: %d\n", keycode);
	return (0);
}

int	put_image_to_window(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
