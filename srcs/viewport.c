/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:57:03 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/11 17:45:49 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_to_viewport(int x, int y, t_fractol *fractol)
{
	double	scale_x;
	double	scale_y;

	scale_x = (fractol->x_max - fractol->x_min) / WIDTH;
	scale_y = (fractol->y_max - fractol->y_min) / HEIGHT;
	fractol->x_view = fractol->x_min + x * scale_x;
	fractol->y_view = fractol->y_min + y * scale_y;
}
