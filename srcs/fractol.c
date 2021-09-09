/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 02:10:12 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/08 23:51:49 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_input_error(int argc, char *fractol);
static void	parse_fractal(char *fractol);

int	main(int argc, char *argv[])
{
	char	*fractol;

	fractol = argv[1];
	check_input_error(argc, fractol);
	parse_fractal(fractol);
	exit(EXIT_SUCCESS);
}

static void	check_input_error(int argc, char *fractol)
{
	if (argc == 1)
	{
		printf("\n[ERROR]\n\n");
		printf("Choose a fractal set: Mandelbrot or Julia.\n\n");
		printf("Ex: ./fract-ol mandelbrot\nEx: ./fract-ol julia\n\n");
		exit(EXIT_FAILURE);
	}
	if (argc > 2)
	{
		printf("\n[ERROR]\n\n");
		printf("Choose just one fractal set: Mandelbrot or Julia.\n\n");
		printf("Ex: ./fract-ol mandelbrot\nEx: ./fract-ol julia\n\n");
		exit(EXIT_FAILURE);
	}
	if (!(ft_strcmp(ft_strtolower(fractol), "mandelbrot") == 0
			|| ft_strcmp(ft_strtolower(fractol), "julia") == 0))
	{
		printf("\n[ERROR]\n\n");
		printf("Choose a valid fractal set: Mandelbrot or Julia.\n\n");
		printf("Ex: ./fract-ol mandelbrot\nEx: ./fract-ol julia\n\n");
		exit(EXIT_FAILURE);
	}
}

static void	parse_fractal(char *fractol)
{
	if (ft_strcmp(ft_strtolower(fractol), "mandelbrot") == 0)
		mandelbrot();
	//if (ft_strcmp(ft_strtolower(fractol), "julia") == 0)
	//	julia();
}
