/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:49:23 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/05 23:47:33 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(int x, int y, t_vars *vars)
{
	char	*dst;

	dst = vars->mlx.addr + (y * vars->mlx.len + x * (vars->mlx.bpp / 8));
	*(int *)dst = color(vars);
}

int	put_image_to_window(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx.ptr, vars->mlx.win, vars->mlx.img, 0, 0);
	return (0);
}

void	reset_image(t_vars *vars)
{
	set_limits(vars);
	render_frame(vars);
}
