/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariasavinova <mariasavinova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:05:45 by marlean           #+#    #+#             */
/*   Updated: 2022/07/04 19:01:46 by mariasavino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void draw_objects(t_data *data, t_coord *ray, int *color, int *ind)
{
	int i = *ind;
	int s = 0;

	while (s < data->objects.nsphere)
	{
		if (sphere_intersect(data->scene.camera, *ray, &data->objects.sphere[s]))
		{
			*color = set_color(data->objects.sphere[s].color);
			i++;
			*ind = i;
			return;
		}
		s++;
	}
	*color = 0;
}
void ray_tracing(t_data *data)
{
	// (void)data;
	// printf("In ray_tracing\n");
	// printf("data->screen->height = %f\n", data->screen.height);
	// printf("data->scene.camera.view_point.x = %f\n", data->scene.camera.view_point.x);
	int mlx_x;
	int mlx_y;
	double x_angle;
	double y_angle;
	int color;
	double x_ray;
	double y_ray;
	t_coord ray;
	int i = 0;

	mlx_y = 0;
	y_angle = HEIGHT / 2;
	printf("start i = % d\n", i);
	while (y_angle > (-1 * HEIGHT / 2))
	{
		y_ray = y_angle * data->screen.y_pixel;
		x_angle = -1 * WIDTH / 2;
		mlx_x = 0;
		while (x_angle < WIDTH / 2)
		{
			x_ray = x_angle * data->screen.x_pixel;
			ray = new_vector3(x_ray, y_ray, -1); // -1 только когда камера в 000 и направлена на -1
												 //			printf("x_angle = %f, data->screen.x_pixel = %f, ray.x = %f, ray.y = %f, ray.z = %f\n", x_angle, data->screen.x_pixel, ray.x, ray.y, ray.z);
			vector_normalize(&ray);
			draw_objects(data, &ray, &color, &i);
			mlx_pixel_put(data->mlx, data->window, mlx_x, mlx_y, color);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
	printf("i = % d\n", i);
}

void draw(t_data *data)
{

	ray_tracing(data);
}
