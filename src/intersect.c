/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/14 16:07:53 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float sphere_intersect(struct s_camera cam, t_coord ray, t_sphere *sphere)
{
	float	b;
	float	c;
	float	discr;
	float	dist;
	float	dist2;
	t_coord	cam_sphere;

 	cam_sphere = vector_subtract(cam.view_point, sphere->coord);
	b = 2.0f * (vector_scalar(cam_sphere, ray));
	c = vector_scalar(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4.0f * c);
	if (discr < 0)
		return (0);
	dist = (-1 * b - sqrtf(discr)) / 2;
	dist2 = (-1 * b + sqrtf(discr)) / 2;
	if (dist > 0.0f)
		return (dist);
	else if (dist2 > 0)
		return (dist2);
	return (0);
}

t_coord vector3_negate(t_coord a)
{
    a.x = -a.x;
    a.y = -a.y;
    a.z = -a.z;
    return (a);
}

float plane_intersect(struct s_camera cam, t_coord ray,  t_plane *plane)
{
	t_coord pc;
	t_coord	d;
	float pn;
	float ln;
	float c;
	float dist;
	
	pc = vector_subtract(plane->coord, cam.view_point);
	pn = vector_scalar(pc, plane->orient_vector);
	ln = vector_scalar(ray, plane->orient_vector);
	c = vector_scalar(plane->orient_vector, ray);
	d = vector_subtract(plane->coord, cam.view_point);
   // if (c > 1e-6)
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

float	disc_intersect(struct s_camera cam, t_coord ray,  t_plane *plane, float r)
{
	t_coord	p;
	t_coord	v;
	float d;
	float t;
	float dist;
	
	t = 0;
	t = plane_intersect(cam, ray, plane);
	if (t != 0.0f)
	{
		vector_multiply(&ray, t);
		p = vector_addition(cam.view_point, ray);
		v = vector_subtract(p, plane->coord); 
		d = vector_scalar(v, v);
		dist = sqrtf(d);
		if (p.x == plane->coord.x && p.y == plane->coord.y && p.z == plane->coord.z)
			return (t);
		if (dist <= r)
		{
			return (t);
		}
	}
	return (0);
}

void	get_discr(struct s_camera cam, t_coord ray,  t_cylind *cylind, t_coef *coef) 
{
	t_coord cam_cy;
	// float	a;
	// float	b;
	// float	c;
	// float	discr;

	cam_cy = vector_subtract(cylind->coord, cam.view_point);
	vector_normalize(&cylind->orient_vector);
	coef->a = 1 - pow(vector_scalar(ray, cylind->orient_vector), 2);
	coef->b = -2 * (vector_scalar(ray, cam_cy) - vector_scalar(ray, cylind->orient_vector) * vector_scalar(cam_cy,cylind->orient_vector));
	coef->c = vector_scalar(cam_cy, cam_cy) - pow(vector_scalar(cam_cy, cylind->orient_vector), 2) - (cylind->diameter / 2) * (cylind->diameter / 2);
	coef->discr = (coef->b * coef->b) - (4.0f * coef->a * coef->c);
}

float	pipe_intersect(struct s_camera cam, t_coord ray,  t_cylind *cylind)
{
	float	m;
	float	dist1;
	float	dist2;
	float	dist_min;
	t_coef	coef;
	t_coord cam_cy;

	dist_min = 100000000000.0f;
	cam_cy = vector_subtract(cylind->coord, cam.view_point);
	get_discr(cam, ray, cylind, &coef);
	if (coef.discr  >= 0.0f)
	{
		dist1 = (-coef.b - sqrtf(coef.discr)) / (2 * coef.a);
		dist2 = (-coef.b + sqrtf(coef.discr)) / (2 * coef.a);
		m = vector_scalar(ray, cylind->orient_vector) * dist1 - vector_scalar(cam_cy, cylind->orient_vector);
		if (dist1 > 0.0f && m >= 0 && m <= cylind->height && dist1 < dist2)
		{
			
			dist_min = dist1;
		}
		m = vector_scalar(ray, cylind->orient_vector) * dist2 - vector_scalar(cam_cy, cylind->orient_vector);
		if (dist2 > 0.0f && m >= 0 && m <= cylind->height && dist_min < 0) //проверить это условие
		{
			dist_min = dist2; 
		}
	}
	return(dist_min);
}

float   cylindr_intersect(struct s_camera cam, t_coord ray,  t_cylind *cylind, t_dist *dist, int *i)
{

    float   dist3;
    float   dist4;
    float   dist_min;
    t_coord disc2;
    t_plane plane;

	dist_min = pipe_intersect(cam, ray, cylind);
    plane.coord = cylind->coord;
    plane.orient_vector = cylind->orient_vector;
    plane.color = cylind->color;
    dist3 = disc_intersect(cam, ray, &plane, (cylind->diameter)/2);
    if (dist3 > 0.0f && dist3 < dist_min)
    {
        dist_min = dist3;
    }
    disc2 = cylind->orient_vector;
    vector_multiply(&disc2, cylind->height);
    plane.coord = vector_addition(cylind->coord, disc2);
    plane.orient_vector = cylind->orient_vector;
    dist4 = disc_intersect(cam, ray, &plane, (cylind->diameter)/2);
    if (dist4 > 0.0f && dist4 < dist_min)
    {
        dist_min = dist4;
    }
    if (dist_min > 0.0f && dist_min != 100000000000.0f)
	{
		if (dist_min < dist->min_dist)
		{
			dist->min_dist = dist_min;
			dist->near_obj = 3;
			if (dist_min == dist3)
				dist->near_obj = 4;
			if (dist_min == dist4)
				dist->near_obj = 5;
			dist->n_obj = *i;
		}
        return (dist_min);
	}
    return (0);
}