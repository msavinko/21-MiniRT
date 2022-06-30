/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:24:43 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 18:53:58 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	fill_color(int *ind, char *str, t_color *color)
{
	int	i;

	i = *ind;
	color->r = ft_atoi(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	color->g = ft_atoi(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	color->b = ft_atoi(&str[i]);
	*ind = i;
}

void	fill_coord(int *ind, char *str, t_coord *coord)
{
	int	i;

	i = *ind;
	coord->x = ft_atof(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	coord->y = ft_atof(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	coord->z = ft_atof(&str[i]);
	*ind = i;
}

void	fill_a(char *str, t_alight *alight)
{
	int	i;

	i = 1;
	while (ft_isspace(str[i]))
		i++;
	alight->light_range = ft_atof(&str[i]);
	if (alight->light_range < 0.0f || alight->light_range > 1.0f)
		error_parser("Ambient lighting ratio not in range 0.0 - 1.0");
	while (!ft_isspace(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	fill_color(&i, str, &alight->color);
	if (alight->color.r < 0 || alight->color.r > 255
		|| alight->color.g < 0 || alight->color.g > 255
		|| alight->color.b < 0 || alight->color.b > 255)
		error_parser("R,G,B colors not in range 0-255");
}

void	fill_c(char *str, t_camera *camera)
{
	int	i;

	i = 1;
	while (ft_isspace(str[i]))
		i++;
	fill_coord(&i, str, &camera->view_point);
	while (!ft_isspace(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	fill_coord(&i, str, &camera->orient_vector);
	if (camera->orient_vector.x < -1.0f || camera->orient_vector.x > 1.0f
		|| camera->orient_vector.y < -1.0f || camera->orient_vector.y > 1.0f
		|| camera->orient_vector.z < -1.0f || camera->orient_vector.z > 1.0f)
		error_parser("3d normalized orientation vector. In range [-1,1]\
		for each x,y,z axis");
	while (!ft_isspace(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	camera->horiz_degrees = ft_atof(&str[i]);
	if (camera->horiz_degrees < 0.0f || camera->horiz_degrees > 180.0f)
		error_parser("Horizontal field of view in degrees in range [0,180]");
}

void	fill_l(char *str, t_light *light)
{
	int	i;

	i = 1;
	while (ft_isspace(str[i]))
		i++;
	fill_coord(&i, str, &light->coord);
	while (!ft_isspace(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	light->bright = ft_atof(&str[i]);
	if (light->bright < 0.0f || light->bright > 1.0f)
		error_parser("The light brightness ratio in range [0.0,1.0]");
}
