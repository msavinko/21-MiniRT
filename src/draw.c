/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:05:45 by marlean           #+#    #+#             */
/*   Updated: 2022/07/13 15:35:54 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
// void shadow(t_data *data, t_dist *dist, t_coord *ray)
// {

// }

float dot_normal(t_data *data, t_dist *dist, t_coord *ray)
{
	t_coord normal;
	float intens_light;

	if (dist->near_obj == 1)//точка, которую мы рисуем на сфере
	{
		normal.x = ray->x - data->objects.sphere[dist->n_obj].coord.x;
		normal.y = ray->y - data->objects.sphere[dist->n_obj].coord.y;
		normal.z = ray->z - data->objects.sphere[dist->n_obj].coord.z;
	}
	else if (dist->near_obj == 2)
	{
		normal.x = data->objects.plane[dist->n_obj].coord.x;
		normal.y = data->objects.plane[dist->n_obj].coord.y;
		normal.z = data->objects.plane[dist->n_obj].coord.z;
	}
	vector_normalize(&normal);
	vector_normalize(dist->dot_light);
	intens_light = vector_scalar(*dist->dot_light, normal);// \
	// 	/ vector_length(*dist->dot_light) / vector_length(normal);
	if (intens_light < 0)
		intens_light = 0;
//	printf("intens_light = %f\n", intens_light);
	return (intens_light);
}

void draw_objects(t_data *data, t_coord *ray, int *color)
{
	t_dist dist;
	float intens_light;

	dist.dot_light = malloc(sizeof(t_coord));
	dist.dot_normal = malloc(sizeof(t_coord));
	dist.near_obj = 0;
	dist.min_dist = INT32_MAX;
	nearest_sphere(data, &dist, ray);
	nearest_plane(data, &dist, ray);
	nearest_cylind(data, &dist, ray);

	vector_multiply(ray, dist.min_dist);							  // ray теперь точка в пространстве на ближайшем объекте, а не точка на видоискателе камеры
	*dist.dot_light = vector_subtract(data->scene.light.coord, *ray); //вектор из этой точки до источника света
	intens_light = dot_normal(data, &dist, ray);
	if (dist.dot_light)
		free(dist.dot_light);
	if (dist.dot_normal)
		free(dist.dot_normal);
	if (shadow_sphere(data, &dist, ray))
	{
		// printf("!!\n");
		*color = draw_dot(data, &dist, 0);
	}
	if (shadow_plane(data, &dist, ray))
		*color = draw_dot(data, &dist, 0);
	// else if (shadow_cylinder)
	// *color = draw_dot(data, &dist, 0);
	else
	{
		// printf("intens_light %f\n", intens_light);
		*color = draw_dot(data, &dist, intens_light);
	}
//	printf("intens_light = %f\n", intens_light);
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
	y_angle = HEIGHT / 2.0f + (data->scene.camera.orient_vector.y * HEIGHT / 2.0f);

	while (y_angle > (-1 * HEIGHT / 2.0f + (data->scene.camera.orient_vector.y * HEIGHT / 2.0f)))
	{
		y_ray = y_angle * data->screen.y_pixel;
		x_angle = -1.0f * WIDTH / 2.0f + (data->scene.camera.orient_vector.x * WIDTH / 2.0f);
		mlx_x = 0;
		while (x_angle < WIDTH / 2.0f + (data->scene.camera.orient_vector.x * WIDTH / 2.0f))
		{
			x_ray = x_angle * data->screen.x_pixel;
			ray = new_vector3(x_ray, y_ray, data->scene.camera.orient_vector.z); // -1 только когда камера в 000 и направлена на -1
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
