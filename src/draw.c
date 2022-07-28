/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:05:45 by marlean           #+#    #+#             */
/*   Updated: 2022/07/28 14:49:01 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	dist_init(t_dist *dist, t_data *data, t_coord *ray)
{
	dist->dot_light = malloc(sizeof(t_coord));
	dist->near_obj = 0;
	dist->n_obj = -1;
	dist->min_dist = INT32_MAX;
	nearest_sphere(data, dist, ray);
	nearest_plane(data, dist, ray);
	nearest_cylind(data, dist, ray);
}

static void	draw_objects(t_data *data, t_coord *ray, int *color)
{
	t_dist	*dist;
	float	intens_light;

	intens_light = 0.0f;
	dist = malloc(sizeof(t_dist));
	dist_init(dist, data, ray);
	vector_multiply(ray, dist->min_dist);
	*ray = vector_addition(*ray, data->scene.camera.view_point);
	*dist->dot_light = vec_sub(data->scene.light.coord, *ray);
	if (!dist->near_obj)
		*color = BACK;
	else
	{
		intens_light = dot_normal(data, dist, ray);
		if (shadow_sphere(data, dist, ray))
			*color = draw_dot(data, dist, 0);
		else if (shadow_plane(data, dist, ray))
			*color = draw_dot(data, dist, 0);
		else if (shadow_cylinder(data, dist, ray))
			*color = draw_dot(data, dist, 0);
		else
			*color = draw_dot(data, dist, intens_light);
	}
	free(dist->dot_light);
	free(dist);
}

static void	draw2(t_data *data, t_draw *draw)
{
	draw->x_ray = draw->x_angle * data->screen.x_pixel
		+ data->scene.camera.view_point.x;
	*draw->ray = new_vector3(draw->x_ray, draw->y_ray,
			data->scene.camera.orient_vector.z);
	vector_normalize(draw->ray);
	draw_objects(data, draw->ray, &draw->color);
	mlx_pixel_put(data->mlx, data->window,
		draw->mlx_x, draw->mlx_y, draw->color);
	draw->x_angle++;
	draw->mlx_x++;
}

void	draw(t_data *data)
{
	t_draw	*draw;

	draw = malloc(sizeof(t_draw));
	draw->mlx_y = 0;
	draw->y_angle = HEIGHT / 2
		+ (data->scene.camera.orient_vector.y * HEIGHT / 2.0f);
	while (draw->y_angle > (-1 * HEIGHT / 2
			+ (data->scene.camera.orient_vector.y * HEIGHT / 2.0f)))
	{
		draw->y_ray = draw->y_angle * data->screen.y_pixel
			+ data->scene.camera.view_point.y;
		draw->x_angle = -1 * WIDTH / 2
			+ (data->scene.camera.orient_vector.x * WIDTH / 2.0f);
		draw->mlx_x = 0;
		while (draw->x_angle < WIDTH / 2
			+ (data->scene.camera.orient_vector.x * WIDTH / 2.0f))
		{
			draw->ray = malloc(sizeof(t_coord));
			draw2(data, draw);
			free(draw->ray);
		}
		draw->y_angle--;
		draw->mlx_y++;
	}
	free(draw);
}
