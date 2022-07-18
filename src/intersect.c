/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariasavinova <mariasavinova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/18 15:20:23 by mariasavino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float sphere_intersect(struct s_camera cam, t_coord ray, t_sphere *sphere)
{
	t_coef coef;
	float dist;
	float dist2;
	t_coord cam_sphere;

	cam_sphere = vector_subtract(cam.view_point, sphere->coord);
	coef.b = 2.0f * (vector_scalar(cam_sphere, ray));
	coef.c = vector_scalar(cam_sphere, cam_sphere) - (sphere->radius *
													  sphere->radius);
	coef.discr = (coef.b * coef.b) - (4.0f * coef.c);
	if (coef.discr < 0)
		return (0);
	dist = (-1 * coef.b - sqrtf(coef.discr)) / 2;
	dist2 = (-1 * coef.b + sqrtf(coef.discr)) / 2;
	if (dist > 0.0f)
		return (dist);
	else if (dist2 > 0)
		return (dist2);
	return (0);
}

float plane_intersect(struct s_camera cam, t_coord ray, t_plane *plane)
{
	t_coord d;
	float pn;
	float c;
	float dist;

	c = vector_scalar(plane->orient_vector, ray);
	d = vector_subtract(plane->coord, cam.view_point);
	if (c != 0)
	{
		pn = vector_scalar(d, plane->orient_vector);
		dist = pn / c;
		if (dist < 0)
			return (0);
		return (dist);
	}
	return (0);
}

float disc_intersect(t_camera cam, t_coord ray, t_plane *plane, float r)
{
	t_coord p;
	t_coord v;
	float t;
	float dist;

	t = plane_intersect(cam, ray, plane);
	if (t != 0.0f)
	{
		vector_multiply(&ray, t);
		p = vector_addition(cam.view_point, ray);
		v = vector_subtract(p, plane->coord);
		dist = sqrtf(vector_scalar(v, v));
		if (p.x == plane->coord.x && p.y == plane->coord.y && p.z == plane->coord.z)
			return (t);
		if (dist <= r)
			return (t);
	}
	return (0);
}

void pipe_inter(t_camera cam, t_coord ray, t_cylind *cyl, float *d_min)
{
	float m;
	float dist1;
	float dist2;
	t_coef coef;
	t_coord cam_cy;

	cam_cy = vector_subtract(cyl->coord, cam.view_point);
	get_discr(cam, ray, cyl, &coef);
	if (coef.discr >= 0.0f)
	{
		dist1 = (-coef.b - sqrtf(coef.discr)) / (2 * coef.a);
		dist2 = (-coef.b + sqrtf(coef.discr)) / (2 * coef.a);
		m = vector_scalar(ray, cyl->orient_vector) * dist1 -
			vector_scalar(cam_cy, cyl->orient_vector);
		if (dist1 > 0.0f && m >= 0 && m <= cyl->height && dist1 < dist2)
			*d_min = dist1;
		m = vector_scalar(ray, cyl->orient_vector) * dist2 -
			vector_scalar(cam_cy, cyl->orient_vector);
		if (dist2 > 0.0f && m >= 0 && m <= cyl->height && d_min < 0) //проверить это условие
			*d_min = dist2;
	}
	return;
}

float cylindr_intersect(t_data *data, t_coord ray, t_dist *dist, int *i)
{
	float dist_disc[2];
	float dist_min;
	t_coord disc2;
	t_plane plane;

	dist_min = INT32_MAX;
	pipe_inter(data->scene.camera, ray, &data->objects.cylind[*i], &dist_min);
	get_plane(&plane, data->objects.cylind[*i]);
	dist_disc[0] = disc_intersect(data->scene.camera, ray, &plane,
								  (data->objects.cylind[*i].diameter) / 2);
	if (dist_disc[0] > 0.0f && dist_disc[0] < dist_min)
		dist_min = dist_disc[0];
	disc2 = data->objects.cylind[*i].orient_vector;
	vector_multiply(&disc2, data->objects.cylind[*i].height);
	plane.coord = vector_addition(data->objects.cylind[*i].coord, disc2);
	dist_disc[1] = disc_intersect(data->scene.camera, ray, &plane,
								  (data->objects.cylind[*i].diameter) / 2);
	if (dist_disc[1] > 0.0f && dist_disc[1] < dist_min)
		dist_min = dist_disc[1];
	if (dist_min > 0.0f && dist_min != INT32_MAX)
	{
		get_nearest(dist, dist_min, dist_disc, i);
		return (dist_min);
	}
	return (0);
}
