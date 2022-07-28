/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherrie <mcherrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:45:19 by marlean           #+#    #+#             */
/*   Updated: 2022/07/15 14:00:39 by mcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	while_space(int *ind, char *str)
{
	int	i;

	i = *ind;
	while (!ft_isspace(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	*ind = i;
}

void	fill_sp(char *str, t_sphere *sphere)
{
	int	i;

	i = 2;
	while (ft_isspace(str[i]))
		i++;
	fill_coord(&i, str, &sphere->coord);
	while_space(&i, str);
	sphere->radius = ft_atof(&str[i]) / 2;
	while_space(&i, str);
	fill_color(&i, str, &sphere->color);
	if (sphere->color.r < 0 || sphere->color.r > 255 || sphere->color.g < 0
		|| sphere->color.g > 255 || sphere->color.b < 0
		|| sphere->color.b > 255)
		error_parser("R,G,B colors not in range 0-255");
}

void	fill_pl(char *str, t_plane *plane)
{
	int	i;

	i = 2;
	while (ft_isspace(str[i]))
		i++;
	fill_coord(&i, str, &plane->coord);
	while_space(&i, str);
	fill_coord(&i, str, &plane->orient_vector);
	if (plane->orient_vector.x < -1.0f || plane->orient_vector.x > 1.0f
		|| plane->orient_vector.y < -1.0f || plane->orient_vector.y > 1.0f
		|| plane->orient_vector.z < -1.0f || plane->orient_vector.z > 1.0f)
		error_parser("3d normalized orientation vector. In range [-1,1]\
		for each x,y,z axis");
	while_space(&i, str);
	fill_color(&i, str, &plane->color);
	if (plane->color.r < 0 || plane->color.r > 255 || plane->color.g < 0
		|| plane->color.g > 255 || plane->color.b < 0 || plane->color.b > 255)
		error_parser("R,G,B colors not in range 0-255");
}

void	fill_cy(char *str, t_cylind *cylind)
{
	int	i;

	i = 2;
	while (ft_isspace(str[i]))
		i++;
	fill_coord(&i, str, &cylind->coord);
	while_space(&i, str);
	fill_coord(&i, str, &cylind->orient_vector);
	if (cylind->orient_vector.x < -1.0f || cylind->orient_vector.x > 1.0f
		|| cylind->orient_vector.y < -1.0f || cylind->orient_vector.y > 1.0f
		|| cylind->orient_vector.z < -1.0f
		|| cylind->orient_vector.z > 1.0f)
		error_parser("3d normalized orientation vector. In range [-1,1]\
		for each x,y,z axis");
	while_space(&i, str);
	cylind->diameter = ft_atof(&str[i]);
	while_space(&i, str);
	cylind->height = ft_atof(&str[i]);
	while_space(&i, str);
	fill_color(&i, str, &cylind->color);
	if (cylind->color.r < 0 || cylind->color.r > 255 || cylind->color.g < 0
		|| cylind->color.g > 255 || cylind->color.b < 0
		|| cylind->color.b > 255)
		error_parser("R,G,B colors not in range 0-255");
}

void	fill_screen(t_data *data)
{
	data->screen.width = 2 * tanf((data->scene.camera.fov / 2) * (M_PI / 180));
	data->screen.height = data->screen.width * HEIGHT / WIDTH;
	data->screen.x_pixel = data->screen.width / WIDTH;
	data->screen.y_pixel = data->screen.height / HEIGHT;
}
