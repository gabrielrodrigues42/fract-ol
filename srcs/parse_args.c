/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:55:49 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/05 12:04:01 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_help(void);
static void	parse_julia(int argc, char **argv, t_vars *vars);

void	parse_args(int argc, char **argv, t_vars *vars)
{
	vars->set = argv[1];
	if (argc == 1)
		print_help();
	else if (ft_strcmp((ft_strtolower(vars->set)), "mandelbrot") == 0)
		vars->fn = &calculate_mandelbrot;
	else if (ft_strcmp((ft_strtolower(vars->set)), "burningship") == 0)
		vars->fn = &calculate_burningship;
	else if (ft_strcmp((ft_strtolower(vars->set)), "julia") == 0)
		parse_julia(argc, argv, vars);
	else
		print_help();
}

static void	parse_julia(int argc, char **argv, t_vars *vars)
{
	if (argc == 2)
	{
		vars->points.real = 0.0;
		vars->points.imaginary = 0.0;
	}
	else if (argc == 3 || argc == 4)
		print_help();
	else if (!(ft_strcmp(argv[3], "+") == 0))
		print_help();
	else
	{
		vars->points.real = atof(argv[2]);
		vars->points.imaginary = atof(argv[4]);
	}
	vars->fn = &calculate_julia;
}

static void	print_help(void)
{
	printf("\n[INPUT ERROR]\n\n");
	printf("Fractals sets available: Mandelbrot, BurningShip and Julia\n\n");
	printf("Please, enter a valid input. Follow the examples:\n\n");
	printf("Ex: ./fractol mandelbrot\n");
	printf("Ex: ./fractol burningship\n");
	printf("Ex: ./fractol julia\n\n");
	printf("Obs: Input is not case sensitive.\n\n");
	exit(0);
}
