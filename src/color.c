/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherrie <mcherrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:23:16 by marlean           #+#    #+#             */
/*   Updated: 2022/07/14 12:12:53 by mcherrie         ###   ########.fr       */
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

int join_color(float r, float g, float b)
{
	char *part1;
	char *part2;
	char *str_r;
	char *str_g;
	char *str_b;
	int result;

	str_r = ft_dectohex(r);
	str_g = ft_dectohex(g);
	str_b = ft_dectohex(b);

	part1 = ft_strjoin(str_r, str_g);
	part2 = ft_strjoin(part1, str_b);
	// if (r)
	// 	free(str_r);
	// if (g)
	// 	free(str_g);
	// if (b)
	// 	free(str_b);
	// if (part1)
	// 	free(part1);
	result = htoi(part2);
	// if (part2)
	// 	free(part2);
	return (result);
}
unsigned int set_color(t_color color, t_data *data, float flag)// флаг 0 - тень есть, 1 - нет
{
	unsigned long result;
	float r;
	float g;
	float b;
	float tmp;
	float col;

	col = 255.0f;

	tmp = data->scene.alight.color.r * data->scene.alight.light_range + flag * data->scene.light.bright * col;
	if (tmp > col)
		tmp = col;
	r = color.r * tmp / col;
	tmp = data->scene.alight.color.g * data->scene.alight.light_range + flag * data->scene.light.bright * col;
	if (tmp > col)
		tmp = col;
	g = color.g * tmp / col;
	tmp = data->scene.alight.color.b * data->scene.alight.light_range + flag * data->scene.light.bright * col;
	if (tmp > col)
		tmp = col;
	b = color.b * tmp / col;

	result = join_color(r, g, b);

	return (result);
}

int	draw_dot(t_data *data, t_dist *dist, float flag)// флаг 0 - тень есть, 1 - нет
{
	int res;

	if (dist->near_obj == SPHERE)
	{
		res = set_color(data->objects.sphere[dist->n_obj].color, data, flag);
	}
	else if (dist->near_obj == PLANE)
	{
		res = set_color(data->objects.plane[dist->n_obj].color, data, flag);
	}
	else if (dist->near_obj == CYLINDER || dist->near_obj == BOTTOM_DISK
		|| dist->near_obj == TOP_DISK)
	{
		res = set_color(data->objects.cylind[dist->n_obj].color, data, flag);
	}
	else
		res = BACK;
	return (res);
}
