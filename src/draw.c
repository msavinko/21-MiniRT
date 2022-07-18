/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariasavinova <mariasavinova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:05:45 by marlean           #+#    #+#             */
/*   Updated: 2022/07/18 15:10:49 by mariasavino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
void normal_cylind(t_data *data, t_dist *dist, t_coord *ray, t_coord *normal)
{
	float n;
	t_coord *tmp;

	tmp = malloc(sizeof(t_coord));
	*tmp = vector_subtract(data->objects.cylind[dist->n_obj].coord, *ray); //вектор из основания цилиндра до точки
	vector_normalize(&data->objects.cylind[dist->n_obj].orient_vector);
	n = vector_scalar(*tmp, data->objects.cylind[dist->n_obj].orient_vector);
	*tmp = data->objects.cylind[dist->n_obj].orient_vector;
	vector_multiply(tmp, n);
	normal->x = tmp->x - ray->x;
	normal->y = tmp->y - ray->y;
	normal->z = tmp->z - ray->z;
	free(tmp);
}

float dot_normal(t_data *data, t_dist *dist, t_coord *ray)
{
	t_coord normal;
	float intens_light;

	if (dist->near_obj == SPHERE)
	{
		normal.x = ray->x - data->objects.sphere[dist->n_obj].coord.x;
		normal.y = ray->y - data->objects.sphere[dist->n_obj].coord.y;
		normal.z = ray->z - data->objects.sphere[dist->n_obj].coord.z;
	}
	else if (dist->near_obj == PLANE)
	{
		normal.x = data->objects.plane[dist->n_obj].orient_vector.x;
		normal.y = data->objects.plane[dist->n_obj].orient_vector.y;
		normal.z = data->objects.plane[dist->n_obj].orient_vector.z;
	}
	else if (dist->near_obj == CYLINDER)
		normal_cylind(data, dist, ray, &normal);
	else if (dist->near_obj == BOTTOM_DISK)
	{
		normal.x = data->objects.cylind[dist->n_obj].orient_vector.x;
		normal.y = data->objects.cylind[dist->n_obj].orient_vector.y;
		normal.z = data->objects.cylind[dist->n_obj].orient_vector.z;
	}
	else
	{
		normal.x = -1.0f * data->objects.cylind[dist->n_obj].orient_vector.x;
		normal.y = -1.0f * data->objects.cylind[dist->n_obj].orient_vector.y;
		normal.z = -1.0f * data->objects.cylind[dist->n_obj].orient_vector.z;
	}
	//	vector_normalize(&normal);
	//	vector_normalize(dist->dot_light);
	intens_light = vector_scalar(*dist->dot_light, normal) / vector_length(*dist->dot_light) / vector_length(normal);
	if (intens_light < 0.0f)
		intens_light = 0.0f;
	return (intens_light);
}

void draw_objects(t_data *data, t_coord *ray, int *color)
{
	t_dist dist;
	float intens_light;

	dist.dot_light = malloc(sizeof(t_coord));
	dist.near_obj = 0;
	dist.min_dist = INT32_MAX;
	nearest_sphere(data, &dist, ray);
	nearest_plane(data, &dist, ray);
	nearest_cylind(data, &dist, ray); //нашли ближайший объект, заполнили dist

	vector_multiply(ray, dist.min_dist);							  // ray теперь точка в пространстве на ближайшем объекте, а не точка на видоискателе камеры
	*dist.dot_light = vector_subtract(data->scene.light.coord, *ray); //вектор из этой точки до источника света
	intens_light = dot_normal(data, &dist, ray);					  ///
	if (shadow_sphere(data, &dist, ray))
		*color = draw_dot(data, &dist, 0);
	if (shadow_plane(data, &dist, ray))
		*color = draw_dot(data, &dist, 0);
	// else if (shadow_cylinder(data, &dist, ray))
	// 	*color = draw_dot(data, &dist, 0);
	else
		*color = draw_dot(data, &dist, intens_light);
	if (dist.dot_light)
		free(dist.dot_light);
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
	// free_data(data);
}
