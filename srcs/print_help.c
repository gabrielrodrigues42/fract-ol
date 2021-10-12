/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:57:42 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/12 18:00:56 by gandrade         ###   ########.fr       */
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
	printf("Ex: ./fractol julia 0.355 + 0.355i\n\n");
	printf("Obs: Input is not case sensitive.\n\n");
	exit(0);
}
