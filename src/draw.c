/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:05:45 by marlean           #+#    #+#             */
/*   Updated: 2022/07/20 15:21:26 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
//  void normal_cylind(t_data *data, t_dist *dist, t_coord *dot, t_coord *normal)
//  {
// 	float	n;
// 	t_coord	*tmp;

// 	tmp = malloc(sizeof(t_coord));
// 	*tmp = vector_subtract(data->objects.cylind[dist->n_obj].coord, *dot);//вектор из основания цилиндра до точки
// 	vector_normalize(&data->objects.cylind[dist->n_obj].orient_vector);
// 	n = vector_scalar(*tmp, data->objects.cylind[dist->n_obj].orient_vector);
// 	*tmp = data->objects.cylind[dist->n_obj].orient_vector;
// 	vector_multiply(tmp, n);
// 	normal->x = tmp->x - dot->x;
// 	normal->y = tmp->y - dot->y;
// 	normal->z = tmp->z - dot->z;
// 	free(tmp);
//  }

float dot_normal(t_data *data, t_dist *dist, t_coord *dot)
{
	t_coord normal;
	float intens_light;
	float m;
	// (void)data; (void)dot;

	// printf("dist->dist %f, dist->dot_light.x %f, dist->min_dist %f, dist->n_obj %d, dist->near_obj %d\n",
	// 	 dist->dist, dist->dot_light->x, dist->min_dist, dist->n_obj, dist->near_obj);
	if (dist->near_obj == SPHERE)
		normal = vector_subtract(*dot, data->objects.sphere[dist->n_obj].coord);
	else if (dist->near_obj == PLANE)
		normal = new_vector3(data->objects.plane[dist->n_obj].orient_vector.x,
			data->objects.plane[dist->n_obj].orient_vector.y, data->objects.plane[dist->n_obj].orient_vector.z);
	else if (dist->near_obj == CYLINDER)
	{
		vector_normalize(&data->objects.cylind[dist->n_obj].orient_vector);
		m = (vector_scalar(*dot, data->objects.cylind[dist->n_obj].orient_vector)
			+ vector_scalar(data->objects.cylind[dist->n_obj].coord, data->objects.cylind[dist->n_obj].orient_vector));
		normal = vector_multiply1(&data->objects.cylind[dist->n_obj].orient_vector, m);
		normal = vector_subtract(normal, *dot);
	}
	else if (dist->near_obj == TOP_DISK)
		normal = new_vector3(data->objects.cylind[dist->n_obj].orient_vector.x,
			data->objects.cylind[dist->n_obj].orient_vector.y, data->objects.cylind[dist->n_obj].orient_vector.z);
	else
		normal = vector_multiply1(&data->objects.cylind[dist->n_obj].orient_vector, -1.0f);
	vector_normalize(&normal);
	vector_normalize(dist->dot_light);
	intens_light = vector_scalar(*dist->dot_light, normal)
	 	/ vector_length(*dist->dot_light) / vector_length(normal);
	if (intens_light < 0)
		intens_light = 0;
	return (intens_light);
}

void draw_objects(t_data *data, t_coord *ray, int *color)
{
	t_dist *dist = malloc(sizeof(t_dist));
	float intens_light = 0.0f;
	dist->dot_light = malloc(sizeof(t_coord));
	dist->near_obj = 0;
	dist->n_obj = -1;
	dist->min_dist = INT32_MAX;
	nearest_sphere(data, dist, ray);
	nearest_plane(data, dist, ray);
	nearest_cylind(data, dist, ray); //нашли ближайший объект, заполнили dist
	
	vector_multiply(ray, dist->min_dist); // ray теперь точка в пространстве на ближайшем объекте, а не точка на видоискателе камеры
	// когда исправим положение камеры, к ray нужно будет прибавить центр камеры (view_point)
	*dist->dot_light = vector_subtract(data->scene.light.coord, *ray); // вектор из этой точки до источника света
	// *dist->dot_light = vector_subtract(*ray, data->scene.light.coord); // вектор из этой точки до источника света
	if (dist->near_obj)
		intens_light = dot_normal(data, dist, ray);///
	// if (shadow_sphere(data, dist, ray))
	// 	*color = draw_dot(data, dist, 0);
	// if (shadow_plane(data, &dist, ray))
	// 	*color = draw_dot(data, &dist, 0);
	// else if (shadow_cylinder(data, &dist, ray))
	// 	*color = draw_dot(data, &dist, 0);
	// else
		*color = draw_dot(data, dist, intens_light);
	if (dist->dot_light)
		free(dist->dot_light);
	if (dist)
		free(dist);
}

void draw(t_data *data)
{
	int mlx_x;
	int mlx_y;
	int x_angle;
	int y_angle;
	int color;
	float x_ray;
	float y_ray;
	t_coord *ray;

	mlx_y = 0;
	y_angle = HEIGHT / 2;// + (data->scene.camera.orient_vector.y * HEIGHT / 2.0f);
	while (y_angle > (-1 * HEIGHT / 2))// + (data->scene.camera.orient_vector.y * HEIGHT / 2.0f)))
	{
		y_ray = y_angle * data->screen.y_pixel + data->scene.camera.view_point.y;
		x_angle = -1 * WIDTH / 2;// + (data->scene.camera.orient_vector.x * WIDTH / 2.0f);
		mlx_x = 0;
		while (x_angle < WIDTH / 2)// + (data->scene.camera.orient_vector.x * WIDTH / 2.0f))
		{
			ray = malloc(sizeof(t_coord));
			x_ray = x_angle * data->screen.x_pixel + data->scene.camera.view_point.x; // -400 * шаг + координаты камеры = объективная точка в пространстве
			*ray = new_vector3(x_ray, y_ray, -1);
			vector_normalize(ray);
			draw_objects(data, ray, &color);
			mlx_pixel_put(data->mlx, data->window, mlx_x, mlx_y, color);
			x_angle++;
			mlx_x++;
			free(ray);
		}
		y_angle--;
		mlx_y++;
	}
}
