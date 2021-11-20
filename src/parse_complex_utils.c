/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_complex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:28:02 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/18 22:43:58 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	valid_position(char *str, int i, int space);

int	check_valid_characters(char *str)
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

int	count_valid_characters(char *str)
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

int	check_valid_position(char *str)
{
	int	space;
	int	len;
	int	i;

	len = ft_strlen(str);
	if (!(str[len - 1] == 'i'))
		return (1);
	space = 0;
	i = 0;
	if (valid_position(str, i, space) == 1)
		return (1);
	return (0);
}

static int	valid_position(char *str, int i, int space)
{
	while (str[i] != '\0')
	{
		if ((str[i] == '+' || str[i] == '-') && (str[i + 1] == '+'
				|| str[i + 1] == '-'))
			return (1);
		if ((str[i] == '+' || str[i] == '-') && str[i + 1] == ' '
			&& (str[i + 2] == '+' || str[i + 2] == '-'))
			return (1);
		if (str[i] == ' ')
			space++;
		if (str[i] == ' ' && space == 1 && !(str[i + 1] == '+'
				|| str[i + 1] == '-'))
			return (1);
		if (str[i] == ' ' && space == 2 && !(ft_isdigit(str[i + 1]) == 1
				|| str[i + 1] == 'i'))
			return (1);
		if (ft_isdigit(str[i]) == 1 && str[i + 1] == '.'
			&& !(ft_isdigit(str[i + 2]) == 1))
			return (1);
		if (str[i] == '.' && !(ft_isdigit(str[i - 1]) == 1))
			return (1);
		i++;
	}
	return (0);
}
