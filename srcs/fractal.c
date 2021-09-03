/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:39:11 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/02 22:58:53 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_fractal(char *fractal)
{
	if (ft_strcmp(fractal, "Mandelbrot") == 0)
		create_mandelbrot();
	if (ft_strcmp(fractal, "Julia") == 0)
		create_julia();
}
