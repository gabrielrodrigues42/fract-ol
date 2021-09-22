/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:28:35 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/22 20:19:02 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_help(void);
static void	parse_julia(int argc, char **argv, t_fractol *fractol);

void	parse_args(int argc, char **argv, t_fractol *fractol)
{
	fractol->set = argv[1];
	if (argc == 1)
		print_help();
	else if (ft_strcmp(ft_strtolower(fractol->set), "mandelbrot") == 0)
		fractol->f = &create_mandelbrot;
	else if (ft_strcmp(ft_strtolower(fractol->set), "burningship") == 0)
		fractol->f = &create_burning_ship;
	else if (ft_strcmp(ft_strtolower(fractol->set), "julia") == 0)
		parse_julia(argc, argv, fractol);
	else
		print_help();
}

static void	parse_julia(int argc, char **argv, t_fractol *fractol)
{
	if (argc == 2 || argc == 3)
		print_help();
	fractol->real = atof(argv[2]);
	fractol->imaginary = atof(argv[3]);
	fractol->f = &create_julia;
}

static void	print_help(void)
{
	printf("\n[INPUT ERROR]\n\n");
	printf("Please, enter a valid input. Follow the examples:\n\n");
	printf("Example 1: ./fractol Mandelbrot\n");
	printf("Example 2: ./fractol BurningShip\n");
	printf("Example 3: ./fractol Julia X Yi\n\n");
	printf("For Julia set, you need to pass its constant value:\n");
	printf("Which X is a value between -2.0 and 2.0;\n");
	printf("Which Yi is a value between -1.2 and 1.2;\n\n");
	exit(0);
}
