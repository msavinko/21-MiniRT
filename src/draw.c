/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:05:45 by marlean           #+#    #+#             */
/*   Updated: 2022/07/08 14:40:18 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
// void shadow(t_data *data, t_dist *dist, t_coord *ray)
// {
	
// }

void draw_objects(t_data *data, t_coord *ray, int *color)
{
	t_dist dist;

	dist.dot_light = malloc(sizeof (t_coord));
	dist.near_obj = 0;
	dist.min_dist = INT32_MAX;
	nearest_sphere(data, &dist, ray);
	nearest_plane(data, &dist, ray);
	nearest_cylind(data, &dist, ray);

	vector_multiply(ray, dist.min_dist); // точка в пространстве на ближайшем объекте
	*dist.dot_light = vector_subtract(data->scene.light.coord, *ray);//вектор из этой точки до источника света
	// vector_normalize(dist.dot_light);
	if (shadow_sphere(data, &dist, ray)) // тень есть
		*color = draw_dot(data, &dist,1);
	// else if (shadow_plane)
	// *color = draw_dot(data, &dist, 0);
	// else if (shadow_cylinder)
	// *color = draw_dot(data, &dist, 0);
	else
		*color = draw_dot(data, &dist, 0);
		//добавить источник света к цвету

}
void ray_tracing(t_data *data)
{
	int mlx_x;
	int mlx_y;
	float x_angle;
	float y_angle;
	int color;
	float x_ray;
	float y_ray;
	t_coord ray;

	mlx_y = 0;
	y_angle = HEIGHT / 2.0f;

	while (y_angle > (-1 * HEIGHT / 2.0f))
	{
		y_ray = y_angle * data->screen.y_pixel;
		x_angle = -1.0f * WIDTH / 2.0f;
		mlx_x = 0;
		while (x_angle < WIDTH / 2.0f)
		{
			x_ray = x_angle * data->screen.x_pixel;
			ray = new_vector3(x_ray, y_ray, -1.0f); // -1 только когда камера в 000 и направлена на -1
													//			printf("x_angle = %f, data->screen.x_pixel = %f, ray.x = %f, ray.y = %f, ray.z = %f\n", x_angle, data->screen.x_pixel, ray.x, ray.y, ray.z);
			vector_normalize(&ray);
			draw_objects(data, &ray, &color);
			mlx_pixel_put(data->mlx, data->window, mlx_x, mlx_y, color);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}

}

void draw(t_data *data)
{

	ray_tracing(data);
}
