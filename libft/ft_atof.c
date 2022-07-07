/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:32:18 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 18:53:20 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_decimal(const char *str)
{
	double	decimal;
	double	weight;

	decimal = 0;
	weight = 1;
	while (*++str && *str != ',' && !ft_isspace(*str))
	{
		decimal *= 10;
		decimal += *str - '0';
		weight *= 10;
	}
	decimal /= weight;
	return (decimal);
}

static void	atof_min(const char **str, int *neg)
{
	if (*(*str) == '-')
	{
		*neg = -1;
		++(*str);
	}
	else if (*(*str) == '+')
		++(*str);
}

double	ft_atof(const char *str)
{
	int		neg;
	double	value;
	double	decimal;

	neg = 1;
	while (ft_isspace(*str))
		str++;
	atof_min(&str, &neg);
	value = 0;
	while (*str != '.' && *str != ',' && !ft_isspace(*str))
	{
		if (!*str)
			return (neg * value);
		value *= 10;
		value += *str - '0';
		str++;
	}
	if (*str != '.')
		return (value * neg);
	decimal = get_decimal(str);
	return ((value + decimal) * neg);
}
