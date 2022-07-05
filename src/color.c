/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariasavinova <mariasavinova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:23:16 by marlean           #+#    #+#             */
/*   Updated: 2022/07/05 22:29:26 by mariasavino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char *ft_dectohex(unsigned int num)
{
	char *hex;
	char c;
	int i;
	unsigned int temp;

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

unsigned long htoi(const char *s)
{
	int i, n;
	n = 0;
	for (i = 0; s[i] != '\0'; ++i)
	{
		if ((i == 0 && s[i] == '0') || (i == 1 && s[i] == 'x'))
			continue;
		else if (s[i] >= '0' && s[i] <= '9')
			n = 16 * n + (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = 16 * n + (s[i] - '7');
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = 16 * n + (s[i] - 'W');
		else
			return 0;
	}
	return n;
}
float get_color(float color, float light, double bright)
{
	float res;

	if (color < light)
		res = color;
	else
		res = light;
	return (res * bright);
}
unsigned int set_color(t_color color, double l, t_color alight)
{
	unsigned long result;
	char *res;
	float r;
	float g;
	float b;

	r = get_color(color.r, alight.r, l);
	g = get_color(color.g, alight.g, l);
	b = get_color(color.b, alight.b, l);
	res = ft_strjoin(ft_dectohex(r), ft_dectohex(g));
	res = ft_strjoin(res, ft_dectohex(b));
	result = htoi(res);
	return (result);
}