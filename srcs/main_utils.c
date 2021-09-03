/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 01:53:28 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/03 01:54:29 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_input_error(int argc, char *fractal)
{
	if (argc == 1)
	{
		printf("\n[ERROR]\n\n");
		printf("Choose a fractal set: Mandelbrot or Julia.\n\n");
		printf("Ex: ./fract-ol Mandelbrot\nEx: ./fract-ol Julia\n\n");
		exit(EXIT_FAILURE);
	}
	if (argc > 2)
	{
		printf("\n[ERROR]\n\n");
		printf("Choose just one fractal set: Mandelbrot or Julia.\n\n");
		printf("Ex: ./fract-ol Mandelbrot\nEx: ./fract-ol Julia\n\n");
		exit(EXIT_FAILURE);
	}
	if (!(ft_strcmp(fractal, "Mandelbrot") == 0
			|| ft_strcmp(fractal, "Julia") == 0))
	{
		printf("\n[ERROR]\n\n");
		printf("Choose a valid fractal set: Mandelbrot or Julia.\n\n");
		printf("Ex: ./fract-ol Mandelbrot\nEx: ./fract-ol Julia\n\n");
		exit(EXIT_FAILURE);
	}
}

void	parse_fractal(char *fractal)
{
	if (ft_strcmp(fractal, "Mandelbrot") == 0)
		create_mandelbrot();
	if (ft_strcmp(fractal, "Julia") == 0)
		create_julia();
}
