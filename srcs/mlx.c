/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:19:43 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/09 00:00:57 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mlx_destroyer(t_mlx_vars *vars);
static int	key_hook(int keycode, t_mlx_vars *vars);

void	mlx_handler(void)
{
	t_mlx_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "fract-ol");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, mlx_destroyer, &vars);
	mlx_loop(vars.mlx);
}

static int	mlx_destroyer(t_mlx_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}

static int	key_hook(int keycode, t_mlx_vars *vars)
{
	if (keycode == 65307)
		mlx_destroyer(vars);
	printf("Key Pressed: %d\n", keycode);
	return (0);
}
