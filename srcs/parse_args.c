/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:55:49 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/08 22:04:16 by gandrade         ###   ########.fr       */
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
		vars->calculate = &calculate_mandelbrot;
	else if (ft_strcmp((ft_strtolower(vars->set)), "burning-ship") == 0)
		vars->calculate = &calculate_burningship;
	else if (ft_strcmp((ft_strtolower(vars->set)), "julia") == 0)
		parse_julia(argc, argv, vars);
	else
		print_help();
}

static void	parse_julia(int argc, char **argv, t_vars *vars)
{
	int	len;

	len = 0;
	if (argc == 2)
	{
		vars->points.real = 0.0;
		vars->points.imaginary = 0.0;
	}
	else if (argc == 3 || argc == 4 || argc > 5)
		print_help();
	else if (argc >= 4)
		len = ft_strlen(argv[4]);
	else if (!(ft_strcmp(argv[3], "+") == 0))
		print_help();
	else if (!(argv[4][len - 1] == 'i'))
		print_help();
	else
	{
		vars->points.real = ft_atof(argv[2]);
		vars->points.imaginary = ft_atof(argv[4]);
		if (vars->points.real > 2.0 || vars->points.real < -2.0
			|| vars->points.imaginary > 1.5 || vars->points.imaginary < -1.5)
			print_help();
	}
	vars->calculate = &calculate_julia;
}

static void	print_help(void)
{
	printf("\n[INPUT ERROR]\n\n");
	printf("Available fractals: Mandelbrot, Burning Ship and Julia.\n\n");
	printf("Please, enter a valid input. Follow the examples:\n\n");
	printf("Ex: ./fractol mandelbrot\n");
	printf("Ex: ./fractol burning-ship\n");
	printf("Ex: ./fractol julia\n");
	printf("Ex: ./fractol julia 0.355 + 0.355i\n\n");
	printf("Obs: Input is not case sensitive.\n\n");
	exit(0);
}
