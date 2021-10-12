/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:58:00 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/12 18:15:37 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	parse_complex(char **argv, t_vars *vars);
static char	*join_args(char **argv);
static int	check_valid_characters(char *str);
static int	count_valid_characters(char *str);
static int	check_valid_position(char *str);
static void	atocomplex(char **argv, t_vars *vars);

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

static void	parse_complex(char **argv, t_vars *vars)
{
	char	*str;

	str = join_args(argv);
	if (check_valid_characters(str) == 1)
	{
		free(str);
		print_help();
	}
	if (count_valid_characters(str) == 1)
	{
		free(str);
		print_help();
	}
	if (check_valid_position(str) == 1)
	{
		free(str);
		print_help();
	}
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

static int	check_valid_characters(char *str)
{
	while (*str)
	{
		if (!(ft_isdigit(*str) == 1 || *str == '+' || *str == '-'
				|| *str == '.' || *str == 'i' || *str == ' '))
			return (1);
		str++;
	}
	return (0);
}

static int	count_valid_characters(char *str)
{
	int		sign;
	int		dot;
	int		i;

	sign = 0;
	dot = 0;
	i = 0;
	while (*str)
	{
		if (*str == '+' || *str == '-')
			sign++;
		if (*str == '.')
			dot++;
		if (*str == 'i')
			i++;
		str++;
	}
	if (sign > 2 || sign == 0 || dot > 2 || i > 1 || i == 0)
		return (1);
	return (0);
}

static int	check_valid_position(char *str)
{
	int	space;
	int	len;
	int	i;

	len = ft_strlen(str);
	if (!(str[len - 1] == 'i'))
		return (1);
	space = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '+' || str[i] == '-') && (str[i + 1] == '+' || str[i + 1] == '-'))
			return (1);
		if ((str[i] == '+' || str[i] == '-') && str[i + 1] == ' ' && (str[i + 2] == '+' || str[i + 2] == '-'))
			return (1);
		if (str[i] == ' ')
			space++;
		if (str[i] == ' ' && space == 1 && !(str[i + 1] == '+' || str[i + 1] == '-'))
			return (1);
		if (str[i] == ' ' && space == 2 && !(ft_isdigit(str[i + 1]) == 1 || str[i + 1] == 'i'))
			return (1);
		if (ft_isdigit(str[i]) == 1 && str[i + 1] == '.' && !(ft_isdigit(str[i + 2]) == 1))
			return (1);
		if (str[i] == '.' && !(ft_isdigit(str[i - 1]) == 1))
			return (1);
		i++;
	}
	return (0);
}

static void	atocomplex(char **argv, t_vars *vars)
{
	char	*str;
	int		len;

	str = ft_strjoin(argv[3], argv[4]);
	len = ft_strlen(str);
	if (str[len - 1] == 'i' && !(ft_isdigit(str[len - 2]) == 1) && str[len - 2] == '+')
		vars->points.imaginary = -1;
	else if (str[len - 1] == 'i' && !(ft_isdigit(str[len - 2]) == 1) && str[len - 2] == '-')
		vars->points.imaginary = 1;
	else
		vars->points.imaginary = ft_atof(str) * -1;
	vars->points.real = ft_atof(argv[2]);
	free(str);
}
