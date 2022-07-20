/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:45:19 by marlean           #+#    #+#             */
/*   Updated: 2022/07/20 13:48:09 by marlean          ###   ########.fr       */
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
	t_coord	d;
	t_coord	r;
	t_coord	o;

	data->screen.width = 2 * tanf((data->scene.camera.fov / 2) * (M_PI / 180));
	data->screen.height = data->screen.width * HEIGHT / WIDTH;
	vector_normalize(&data->scene.camera.orient_vector);
	o = vector_add(data->scene.camera.view_point,
			data->scene.camera.orient_vector);
	d.y = o.y;
	d.z = o.z + data->screen.width / 2.0f
		/ sqrtf(pow((data->scene.camera.view_point.z
			- o.z) / (data->scene.camera.view_point.x - o.x), 2) + 1.0f);
	d.x = o.x - (d.z - o.z) / (data->scene.camera.view_point.z - o.z);
	r.x = o.x;
	r.z = o.z + data->screen.height / 2.0f
		/ sqrtf(pow((data->scene.camera.view_point.z
			- o.z) / (data->scene.camera.view_point.y - o.y), 2) + 1.0f);
	r.y = o.y - (r.z - o.z) * (data->scene.camera.view_point.z - o.z)
		/ (data->scene.camera.view_point.y - o.y);
	data->screen.start = vector_add(vector_subtract(r, o),
		vector_subtract(d, o));
	data->screen.start = vector_add(data->screen.start, o);
	data->screen.step_w = vector_subtract(r, data->screen.start);
	vector_multiply(&data->screen.step_w, data->screen.width / WIDTH);
	data->screen.step_h = vector_subtract(d, data->screen.start);
	vector_multiply(&data->screen.step_h, data->screen.height / HEIGHT);

	printf("\n\nstart x: %f, start y: %f, start z: %f\n", data->screen.start.x, data->screen.start.y, data->screen.start.z);
	printf("\nd.x: %f d.y: %f d.z: %f\n", d.x, d.y, d.z);
	printf("\nr.x: %f r.y: %f r.z: %f\n", r.x, r.y, r.z);
	printf("\no.x: %f o.y: %f o.z: %f\n", o.x, o.y, o.z);
	printf("\ndata->screen.step_w.x: %f, data->screen.step_w.y: %f, data->screen.step_w.z: %f\n", data->screen.step_w.x, data->screen.step_w.y, data->screen.step_w.z);
	printf("data->screen.step_h.x: %f, data->screen.step_h.y: %f, data->screen.step_h.z: %f\n", data->screen.step_h.x, data->screen.step_h.y, data->screen.step_h.z);
	printf("data->screen.width: %f, data->screen.height %f\n", data->screen.width, data->screen.height);
}
