/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherrie <mcherrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:23:16 by marlean           #+#    #+#             */
/*   Updated: 2022/07/15 13:12:34 by mcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*ft_dectohex(int num)
{
	char	*hex;
	char	c;
	int		i;
	int		temp;

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

static int	htoi(const char *s)
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

static void	join_color(float r, float g, float b, int *result)
{
	char	*part1;
	char	*part2;
	char	*str_r;
	char	*str_g;
	char	*str_b;

	str_r = ft_dectohex(r);
	str_g = ft_dectohex(g);
	str_b = ft_dectohex(b);
	part1 = ft_strjoin(str_r, str_g);
	part2 = ft_strjoin(part1, str_b);
	free(str_r);
	free(str_g);
	free(str_b);
	free(part1);
	*result = htoi(part2);
	free(part2);
}

static int	set_color(t_color color, t_data *data, float intens_light)
{
	int		result;
	float	r;
	float	g;
	float	b;
	float	tmp;

	tmp = data->scene.alight.color.r * data->scene.alight.light_range \
		+ intens_light * data->scene.light.bright * 255.0f;
	if (tmp > 255.0f)
		tmp = 255.0f;
	r = color.r * tmp / 255.0f;
	tmp = data->scene.alight.color.g * data->scene.alight.light_range \
		+ intens_light * data->scene.light.bright * 255.0f;
	if (tmp > 255.0f)
		tmp = 255.0f;
	g = color.g * tmp / 255.0f;
	tmp = data->scene.alight.color.b * data->scene.alight.light_range \
		+ intens_light * data->scene.light.bright * 255.0f;
	if (tmp > 255.0f)
		tmp = 255.0f;
	b = color.b * tmp / 255.0f;
	join_color(r, g, b, &result);
	return (result);
}

int	draw_dot(t_data *data, t_dist *dist, float intens_light)// флаг 0 - тень есть, 1 - нет
{
	int	res;

	if (dist->near_obj == SPHERE)
		res = set_color(data->objects.sphere[dist->n_obj].color, data, \
																intens_light);
	else if (dist->near_obj == PLANE)
		res = set_color(data->objects.plane[dist->n_obj].color, data, \
																intens_light);
	else if (dist->near_obj == CYLINDER || dist->near_obj == BOTTOM_DISK
		|| dist->near_obj == TOP_DISK)
		res = set_color(data->objects.cylind[dist->n_obj].color, data, \
																intens_light);
	else
		res = BACK;
	return (res);
}
