/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:28:35 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/11 23:40:15 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_error(void);

void	parse_args(int argc, char **argv, t_fractol *fractol)
{
	fractol->set = argv[1];
	if (argc == 1)
		print_error();
	else if (ft_strcmp(ft_strtolower(fractol->set), "mandelbrot") == 0)
		fractol->f = &create_mandelbrot;
	else if (ft_strcmp(ft_strtolower(fractol->set), "julia") == 0)
		fractol->f = &create_julia;
	else
		print_error();
}

static void	print_error(void)
{
	printf("\n[ERROR]\n\n");
	printf("Please, enter a valid input. Follow the example.\n\n");
	printf("Example: ./fractol mandelbrot\n	 ./fractol julia\n\n");
	exit(0);
}
