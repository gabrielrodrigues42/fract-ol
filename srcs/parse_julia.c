/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:58:00 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/12 19:26:53 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_julia(int argc, char **argv, t_vars *vars)
{
	if (argc == 2)
		set_julia(vars);
	else if (argc == 3 || argc == 4 || argc > 5)
		print_help();
	else
		parse_complex(argv, vars);
	vars->calculate = &calculate_julia;
}
