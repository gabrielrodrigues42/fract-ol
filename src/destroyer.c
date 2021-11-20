/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:34:34 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/04 20:59:25 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroyer(t_vars *vars)
{
	mlx_destroy_image(vars->mlx.ptr, vars->mlx.img);
	mlx_clear_window(vars->mlx.ptr, vars->mlx.win);
	mlx_destroy_window(vars->mlx.ptr, vars->mlx.win);
	mlx_destroy_display(vars->mlx.ptr);
	free(vars->mlx.ptr);
	exit(0);
}
