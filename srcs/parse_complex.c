/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:27:00 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/19 20:44:21 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char	*join_args(char **argv);
static void	atocomplex(char **argv, t_vars *vars);

void	parse_complex(char **argv, t_vars *vars)
{
	char	*str;

	str = join_args(argv);
	if (check_valid_characters(str) == 1)
	{
		free(str);
		print_help();
	}
	else if (count_valid_characters(str) == 1)
	{
		free(str);
		print_help();
	}
	else if (check_valid_position(str) == 1)
	{
		free(str);
		print_help();
	}
	else
		atocomplex(argv, vars);
	free(str);
}

static char	*join_args(char **argv)
{
	char	*str;
	char	*temp;

	str = ft_strjoin(argv[2], " ");
	temp = str;
	str = ft_strjoin(str, argv[3]);
	free(temp);
	temp = str;
	str = ft_strjoin(str, " ");
	free(temp);
	temp = str;
	str = ft_strjoin(str, argv[4]);
	free(temp);
	return (str);
}

static void	atocomplex(char **argv, t_vars *vars)
{
	char	*str;
	int		len;

	str = ft_strjoin(argv[3], argv[4]);
	len = ft_strlen(str);
	if (str[len - 1] == 'i' && ft_isdigit(str[len - 2]) == 0
		&& str[len - 2] == '+')
		vars->points.imaginary = -1;
	else if (str[len - 1] == 'i' && ft_isdigit(str[len - 2]) == 0
		&& str[len - 2] == '-')
		vars->points.imaginary = 1;
	else
		vars->points.imaginary = ft_atof(str) * -1;
	vars->points.real = ft_atof(argv[2]);
	free(str);
}
