/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:55:49 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/25 12:35:38 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_help(void);

void	parse_args(int argc, char **argv, t_vars *vars)
{
	vars->fractol.set = argv[1];
	if (argc == 1)
		print_help();
	else if (ft_strcmp((ft_strtolower(vars->fractol.set)), "mandelbrot") == 0)
		vars->fn = &calculate_mandelbrot;
	else if (ft_strcmp((ft_strtolower(vars->fractol.set)), "burningship") == 0)
		vars->fn = &calculate_burningship;
	else if (ft_strcmp((ft_strtolower(vars->fractol.set)), "julia") == 0)
		vars->fn = &calculate_julia;
	else
		print_help();
}

static void	print_help(void)
{
	printf("\n[INPUT ERROR]\n\n");
	printf("Please, enter a valid input. Follow the examples:\n\n");
	printf("Example 1: ./fractol mandelbrot\n");
	printf("Example 2: ./fractol burningship\n");
	printf("Example 2: ./fractol julia\n\n");
	printf("Obs: Input is not case sensitive.\n\n");
	exit(0);
}
