/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 02:10:12 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/03 21:33:39 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_input_error(int argc, char *fractal);
static void	parse_fractal(char *fractal);

int	main(int argc, char *argv[])
{
	char	*fractal;

	fractal = argv[1];
	check_input_error(argc, fractal);
	parse_fractal(fractal);
	exit(EXIT_SUCCESS);
}

static void	check_input_error(int argc, char *fractal)
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

static void	parse_fractal(char *fractal)
{
	if (ft_strcmp(fractal, "Mandelbrot") == 0)
		create_mandelbrot();
	//if (ft_strcmp(fractal, "Julia") == 0)
	//	create_julia();
}
