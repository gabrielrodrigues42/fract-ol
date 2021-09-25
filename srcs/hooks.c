/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:39:04 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/25 18:26:21 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_vars *vars)
{
	if (key == ESC)
		destroyer(vars);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_vars *vars)
{
	if (key == SCROLL_DOWN)
		zoom_in(x, y, vars);
	if (key == SCROLL_UP)
		zoom_out(x, y, vars);
	return (0);
}

// int	mouse_motion_hook(int x, int y)
// {
// 	printf("x: %d, y: %d\n", x, y);
// 	return (0);
// }
