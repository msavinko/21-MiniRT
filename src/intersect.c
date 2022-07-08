/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/08 12:49:57 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float sphere_intersect(struct s_camera cam, t_coord ray, t_sphere *sphere)
{
	float	b;
	float	c;
	float	discr;
	float	dist;
	t_coord	cam_sphere;

 	cam_sphere = vector_subtract(cam.view_point, sphere->coord);
	b = 2.0f * (vector_scalar(cam_sphere, ray));
	c = vector_scalar(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4.0f * c);
	if (discr < 0)
		return (0);
	dist = (-1 * b - sqrt(discr)) / 2;
	if (dist > 0.0f)
		return (dist);
	return (0);
}

float	plane_intersect(struct s_camera cam, t_coord ray,  t_plane *plane)
{
	float	d;
	float c;
	float pn;
	float dist;

	c = vector_scalar(plane->orient_vector, ray);
	if (c == 0)
		return (0);
	d =  plane->coord.z; 
	pn = vector_scalar(cam.view_point, plane->orient_vector);
	dist = (d - pn) /c;
	if (dist < 0)
		return (0);
	return (dist);

}

float	cylindr_intersect(struct s_camera cam, t_coord ray,  t_cylind *cylind)
{
	float	dist;
	float	a;
	float	b;
	float	c;
	float m;
	float	discr;
	t_coord	cam_cy;

	cam_cy = vector_subtract(cylind->coord, cam.view_point);
	vector_normalize(&cylind->orient_vector);
	a = 1 - pow(vector_scalar(ray, cylind->orient_vector), 2);
	b = -2 * (vector_scalar(ray, cam_cy) - vector_scalar(ray, cylind->orient_vector) * vector_scalar(cam_cy,cylind->orient_vector));
	c = vector_scalar(cam_cy, cam_cy) - pow(vector_scalar(cam_cy, cylind->orient_vector), 2) - (cylind->diameter / 2) * (cylind->diameter / 2);
	discr = (b * b) - (4.0f *a * c);
	if (discr < 0)
		return (0);
	dist = (-b - sqrtf(discr)) / (2 * a);
	m = vector_scalar(ray, cylind->orient_vector) * dist - vector_scalar(cam_cy, cylind->orient_vector);
	if (dist > 0 && m >= 0 && m <= cylind->height)
		return (dist);
	return (0);
}