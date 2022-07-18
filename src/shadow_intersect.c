/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariasavinova <mariasavinova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/18 15:20:55 by mariasavino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int shadow_sphere_intersect(t_coord *dot_light, t_sphere *sphere, t_coord *dot_sphere)
{
	float b;
	float c;
	float discr;
	float dist;

	// printf("dot_sphere x %f, y %f, z %f\n", dot_sphere->x, dot_sphere->y, dot_sphere->z);
	b = 2.0f * (vector_scalar(*dot_sphere, *dot_light));
	c = vector_scalar(*dot_sphere, *dot_sphere) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4.0f * c);
	//	printf("discr: %f\n", discr);
	if (discr < 0.0f)
		return (0);
	dist = (-1.0f * b - sqrtf(discr)) / 2.0f;
	if (dist > 0.0f)
		return (dist);
	if (dist < 0.0f)
		dist = (-1.0f * b + sqrtf(discr)) / 2.0f;
	if (dist > 0.0f)
		return (dist);
	return (0);
}

float shadow_plane_intersect(t_coord *dot_light, t_plane *plane, t_coord *dot)
{
	t_coord d;
	float pn;
	float c;
	float dist;

	c = vector_scalar(plane->orient_vector, *dot_light);
	d = vector_subtract(plane->coord, *dot);
	if (c != 0)
	{
		pn = vector_scalar(d, plane->orient_vector);
		dist = pn / c;
		if (dist < 0)
			return (0);
		return (1);
	}
	return (0);
}
float shadow_disk_plane_intersect(t_coord *dot_light, t_coord *dot, t_plane *plane)
{
	t_coord d;
	float pn;
	float c;
	float dist;

	c = vector_scalar(plane->orient_vector, *dot_light);
	d = vector_subtract(plane->coord, *dot);
	if (c != 0) // плоскость не параллельна лучу
	{
		pn = vector_scalar(d, plane->orient_vector);
		dist = pn / c;
		if (dist < 0)
			return (0);
		return (dist);
	}
	return (0);
}
float shadow_disc_intersect(t_coord *dot_light, t_coord *dot, t_plane *plane, float r)
{
	t_coord p;
	t_coord v;
	float t;
	float dist;

	t = shadow_disk_plane_intersect(dot_light, dot, plane);
	if (t != 0.0f)
	{
		vector_multiply(dot_light, t);
		p = vector_addition(*dot, *dot_light);
		v = vector_subtract(p, plane->coord);
		dist = sqrtf(vector_scalar(v, v));
		if (p.x == plane->coord.x && p.y == plane->coord.y && p.z == plane->coord.z)
			return (1);
		if (dist <= r)
			return (1);
	}
	return (0);
}

float shadow_cylindr_intersect(t_coord *dot_light, t_cylind *cylind, t_coord *dot)
{
	t_coord top_disc;
	t_plane plane;

	if (shadow_pipe_intersect(dot_light, cylind, dot))
		return (1);
	plane.coord = cylind->coord;
	plane.orient_vector = cylind->orient_vector;
	plane.color = cylind->color;
	if (shadow_disc_intersect(dot_light, dot, &plane, (cylind->diameter) / 2))
		return (1);
	top_disc = cylind->orient_vector;
	vector_multiply(&top_disc, cylind->height);
	plane.coord = vector_addition(cylind->coord, top_disc);
	plane.orient_vector = cylind->orient_vector;
	if (shadow_disc_intersect(dot_light, dot, &plane, (cylind->diameter) / 2))
		return (1);
	return (0);
}

void shadow_get_discr(t_coord *dot_light, t_cylind *cylind, t_coord *dot, t_coef *coef)
{
	t_coord cam_cy;

	cam_cy = vector_subtract(cylind->coord, *dot);
	vector_normalize(&cylind->orient_vector);
	coef->a = 1 - pow(vector_scalar(*dot_light, cylind->orient_vector), 2);
	coef->b = -2 * (vector_scalar(*dot_light, cam_cy) - vector_scalar(*dot_light,
																	  cylind->orient_vector) *
															vector_scalar(cam_cy, cylind->orient_vector));
	coef->c = vector_scalar(cam_cy, cam_cy) - pow(vector_scalar(cam_cy, cylind->orient_vector), 2) - (cylind->diameter / 2) * (cylind->diameter / 2);
	coef->discr = (coef->b * coef->b) - (4.0f * coef->a * coef->c);
}

float shadow_pipe_intersect(t_coord *dot_light, t_cylind *cylind, t_coord *dot)
{
	float m;
	float dist;
	t_coef coef;
	t_coord cam_cy;

	cam_cy = vector_subtract(cylind->coord, *dot);
	shadow_get_discr(dot_light, cylind, dot, &coef);
	if (coef.discr >= 0.0f)
	{
		dist = (-coef.b - sqrtf(coef.discr)) / (2 * coef.a);
		m = vector_scalar(*dot_light, cylind->orient_vector) * dist - vector_scalar(cam_cy, cylind->orient_vector);
		if (dist > 0.0f && m >= 0 && m <= cylind->height) // пересечение с ближней стенкой
			return (1);
		dist = (-coef.b + sqrtf(coef.discr)) / (2 * coef.a);
		m = vector_scalar(*dot_light, cylind->orient_vector) * dist - vector_scalar(cam_cy, cylind->orient_vector);
		if (dist > 0.0f && m >= 0 && m <= cylind->height) // пересечение сс стенкой если мы внутри цилиндра
			return (1);
	}
	return (0);
}
