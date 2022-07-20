/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherrie <mcherrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:05:45 by marlean           #+#    #+#             */
/*   Updated: 2022/07/16 15:27:46 by mcherrie         ###   ########.fr       */
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

	if (dist->near_obj == SPHERE)
	{
		normal.x = dot->x - data->objects.sphere[dist->n_obj].coord.x;
		normal.y = dot->y - data->objects.sphere[dist->n_obj].coord.y;
		normal.z = dot->z - data->objects.sphere[dist->n_obj].coord.z;
	}
	else if (dist->near_obj == PLANE)
	{
		normal.x = data->objects.plane[dist->n_obj].orient_vector.x;
		normal.y = data->objects.plane[dist->n_obj].orient_vector.y;
		normal.z = data->objects.plane[dist->n_obj].orient_vector.z;
	}
	else if (dist->near_obj == CYLINDER)
	{
		float	n;
		t_coord	tmp;

		tmp.x = data->objects.cylind[dist->n_obj].coord.x - dot->x;//вектор из основания цилиндра до точки
		tmp.y = data->objects.cylind[dist->n_obj].coord.y - dot->y;//вектор из основания цилиндра до точки
		tmp.z = data->objects.cylind[dist->n_obj].coord.z - dot->z;//вектор из основания цилиндра до точки

		vector_normalize(&data->objects.cylind[dist->n_obj].orient_vector);
		n = -vector_scalar(tmp, data->objects.cylind[dist->n_obj].orient_vector);
		normal.x = -(data->objects.cylind[dist->n_obj].orient_vector.x * n + data->objects.cylind[dist->n_obj].coord.x - dot->x);
		normal.y = -(data->objects.cylind[dist->n_obj].orient_vector.y * n + data->objects.cylind[dist->n_obj].coord.y - dot->y);
		normal.z = -(data->objects.cylind[dist->n_obj].orient_vector.z * n + data->objects.cylind[dist->n_obj].coord.z - dot->z);
		vector_normalize(&normal);
		vector_normalize(dist->dot_light);
	}
	else if (dist->near_obj == TOP_DISK)
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
	t_dist dist;
	float intens_light;

	dist.dot_light = malloc(sizeof(t_coord));
	dist.near_obj = 0;
	dist.min_dist = INT32_MAX;
	nearest_sphere(data, &dist, ray);
	nearest_plane(data, &dist, ray);
	nearest_cylind(data, &dist, ray); //нашли ближайший объект, заполнили dist

	vector_multiply(ray, dist.min_dist); // ray теперь точка в пространстве на ближайшем объекте, а не точка на видоискателе камеры
	*dist.dot_light = vector_subtract(data->scene.light.coord, *ray); //вектор из этой точки до источника света
	intens_light = dot_normal(data, &dist, ray);///
	if (shadow_sphere(data, &dist, ray))
		*color = draw_dot(data, &dist, 0);
	// // if (shadow_plane(data, &dist, ray))
	// // 	*color = draw_dot(data, &dist, 0);
	// // else if (shadow_cylinder(data, &dist, ray))
	// // 	*color = draw_dot(data, &dist, 0);
	// else
		*color = draw_dot(data, &dist, intens_light);
	// if (dist.dot_light)
		free(dist.dot_light);
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
	t_coord ray;

	mlx_y = 0;
	y_angle = HEIGHT / 2;// + (data->scene.camera.orient_vector.y * HEIGHT / 2.0f);
	while (y_angle > (-1 * HEIGHT / 2))// + (data->scene.camera.orient_vector.y * HEIGHT / 2.0f)))
	{
		y_ray = y_angle * data->screen.y_pixel + data->scene.camera.view_point.y;
		x_angle = -1 * WIDTH / 2;// + (data->scene.camera.orient_vector.x * WIDTH / 2.0f);
		mlx_x = 0;
		while (x_angle < WIDTH / 2)// + (data->scene.camera.orient_vector.x * WIDTH / 2.0f))
		{
			x_ray = x_angle * data->screen.x_pixel + data->scene.camera.view_point.x; // -400 * шаг + координаты камеры = объективная точка в пространстве
			ray = new_vector3(x_ray, y_ray, -1);
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

// static void	found_ray(t_coord *ray, int w, int h, )
// {
// 	vector_addition(vector_multiply(&step_w, w), vector_multiply(&step_h, h)),  //start + w/W * step_w + h/H * step_h;
// }

// void draw(t_data *data)
// {
// 	int		mlx_x;
// 	int		mlx_y;
// 	int		w;
// 	int		h;
// 	int		color;
// 	t_coord	start;
// 	t_coord	step_w;
// 	t_coord	step_h;
// 	t_coord	*ray;

// 	ray = malloc(sizeof(t_coord));
// 	mlx_y = 0;
// 	h = 0;
// 	while (h < HEIGHT)// движение по экрану вниз
// 	{
// 		w = 0;
// 		mlx_x = 0;
// 		while (w < WIDTH)// движение по экрану направо
// 		{
// 			found_ray(ray, w, h); //start + w/W * step_w + h/H * step_h;
// 			vector_normalize(&ray);
// 			draw_objects(data, &ray, &color);
// 			mlx_pixel_put(data->mlx, data->window, mlx_x, mlx_y, color);
// 			w++;
// 			mlx_x++;
// 		}
// 		h++;
// 		mlx_y++;
// 	}
// 	free(ray);
// }
