/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:56:30 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/08 16:25:00 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	result;
	double	power;
	int		sign;

	result = 0.0;
	power = 1.0;
	sign = 1;
	while (ft_isspace(*str) != 0)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str) != 0)
		result = (result * 10) + (*str++ - '0');
	if (*str == '.')
		str++;
	while (ft_isdigit(*str) != 0)
	{
		result = (result * 10) + (*str++ - '0');
		power *= 10.0;
	}
	return (sign * result / power);
}
