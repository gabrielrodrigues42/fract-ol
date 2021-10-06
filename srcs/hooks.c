/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:39:04 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/05 23:50:09 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_vars *vars)
{
	if (key == ESC)
		destroyer(vars);
	if (key == R)
		reset_image(vars);
	if (key == C)
		change_color(++vars->colors.index % 3, vars);
	if (key == ARROW_UP)
		shift_up(vars);
	if (key == ARROW_DOWN)
		shift_down(vars);
	if (key == ARROW_LEFT)
		shift_left(vars);
	if (key == ARROW_RIGHT)
		shift_right(vars);
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
