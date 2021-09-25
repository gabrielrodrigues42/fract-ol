/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:39:04 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/25 13:57:40 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_vars *vars)
{
	if (key == ESC)
		destroyer(vars);
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
