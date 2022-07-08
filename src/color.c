/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:23:16 by marlean           #+#    #+#             */
/*   Updated: 2022/07/08 14:29:10 by marlean          ###   ########.fr       */
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
	hex = malloc(sizeof(char) * 3);
	hex[3] = '\0';
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
	int i;
	int n;

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

unsigned int set_color(t_color color, t_data *data, int flag)
{
	unsigned long result;
	char *res;
	float r;
	float g;
	float b;
	float tmp;

	tmp = data->scene.alight.color.r * data->scene.alight.light_range + flag * data->scene.light.bright * 255;
	if (tmp > 255)
		tmp = 255;
	r = color.r * tmp / 255;
	tmp = data->scene.alight.color.g * data->scene.alight.light_range + flag * data->scene.light.bright * 255;
	if (tmp > 255)
		tmp = 255;
	g = color.g * tmp / 255;
	tmp = data->scene.alight.color.b * data->scene.alight.light_range + flag * data->scene.light.bright * 255;
	if (tmp > 255)
		tmp = 255;
	b = color.b * tmp / 255;

	res = ft_strjoin(ft_dectohex(r), ft_dectohex(g));
	res = ft_strjoin(res, ft_dectohex(b));
	result = htoi(res);
	return (result);
}

int	draw_dot(t_data *data, t_dist *dist, int flag)
{
	int res;

	if (dist->near_obj == 1)
	{
		res = set_color(data->objects.sphere[dist->n_obj].color, data, flag);
	}
	// else if (dist->near_obj == 2)
	// {
	// 	res = set_color(data->objects.plane[dist->n_obj].color,
	// 			data->scene.alight.light_range, data->scene.alight.color, flag);
	// }
	// else if (dist->near_obj == 3)
	// {
	// 	res = set_color(data->objects.cylind[dist->n_obj].color,
	// 			data->scene.alight.light_range, data->scene.alight.color, flag);
	// }
	else 
		res = BACK;
	return (res);
}
