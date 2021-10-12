/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:55:49 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/10 12:58:40 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
