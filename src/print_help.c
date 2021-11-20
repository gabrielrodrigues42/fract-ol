/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:57:42 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/20 22:55:19 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(void)
{
	printf("\n[INPUT ERROR]\n\n");
	printf("Available fractals: Mandelbrot, Burning Ship and Julia.\n\n");
	printf("Please, enter a valid input. Follow the examples:\n\n");
	printf("Ex: ./fractol mandelbrot\n");
	printf("Ex: ./fractol burning-ship\n");
	printf("Ex: ./fractol julia\n");
	printf("Ex: ./fractol julia <real> <sign> <imaginary>\n");
	printf("    ./fractol julia 0.355 + 0.355i\n");
	printf("    ./fractol julia -0.4 + 0.6i\n\n");
	printf("Obs: Input is not case sensitive;\n");
	printf("     Real part sign is optional;\n");
	printf("     Imaginary part sign is the middle one, and it's mandatory;\n");
	printf("     Imaginary must be followed by the \"i\" character;\n\n");
	exit(0);
}
