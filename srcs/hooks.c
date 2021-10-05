/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:39:04 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/04 21:43:20 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_vars *vars)
{
	if (key == ESC)
		destroyer(vars);
	if (key == R)
	{
		vars->rgb = &red;
		render_frame(vars);
	}
	if (key == G)
	{
		vars->rgb = &green;
		render_frame(vars);
	}
	if (key == B)
	{
		vars->rgb = &blue;
		render_frame(vars);
	}
	return (0);
}

int	mouse_hook(int key, int x, int y, t_vars *vars)
{
	if (key == SCROLL_DOWN)
		zoom(x, y, ZOOM_IN, vars);
	if (key == SCROLL_UP)
		zoom(x, y, ZOOM_OUT, vars);
	if (key == MOUSE_LEFT)
		render_julia_frame(x, y, vars);
	return (0);
}
