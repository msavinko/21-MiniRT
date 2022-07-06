/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:23:16 by marlean           #+#    #+#             */
/*   Updated: 2022/07/06 17:44:42 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_dectohex(unsigned int num)
{
	char			*hex;
	char			c;
	int				i;
	unsigned int	temp;

	if (!num)
		return ("00");
	hex = calloc(2, sizeof(char));
	temp = num;
	i = 1;
	while (i >= 0)
	{
		if (temp % 16 > 9)
			c = 'A' + (temp % 16) - 10;
		else
			c = (temp % 16) + '0';
		*(hex + i) = c;
		temp = temp / 16;
		i--;
	}
	return (hex);
}

unsigned long	htoi(const char *s)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			n = 16 * n + (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = 16 * n + (s[i] - '7');
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = 16 * n + (s[i] - 'W');
		else
			return (0);
		i++;
	}
	return (n);
}

float	get_color(float color, float light, double bright)
{
	float	res;

	if (color < light)
		res = color + light * 0.2;
	else if (color > light)
		res = color * 0.6 + light;
	else
		res = color;
	if (res > 255)
			res = 255;
	else if (res < 0)
		res = 0;
	return (res * bright);
}

unsigned int	set_color(t_color color, double l, t_color alight)
{
	unsigned long	result;
	char			*res;
	float			r;
	float			g;
	float			b;

	r = get_color(color.r, alight.r, l);
	g = get_color(color.g, alight.g, l);
	b = get_color(color.b, alight.b, l);
	res = ft_strjoin(ft_dectohex(r), ft_dectohex(g));
	res = ft_strjoin(res, ft_dectohex(b));
	result = htoi(res);
	return (result);
}
