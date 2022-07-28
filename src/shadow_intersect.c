/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/28 14:52:43 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	shadow_disk_plane_intersect(t_coord *dot_light,
	t_coord *dot, t_plane *plane)
{
	t_coord	d;
	float	pn;
	float	c;
	float	dist;

	c = vec_scl(plane->orient_vector, *dot_light);
	d = vec_sub(plane->coord, *dot);
	if (c != 0)
	{
		pn = vec_scl(d, plane->orient_vector);
		dist = pn / c;
		if (dist < 0)
			return (0);
		return (dist);
	}
	return (0);
}

static float	shadow_disc_intersect(t_coord *dot_light,
	t_coord *dot, t_plane *plane, float r)
{
	t_coord	p;
	t_coord	v;
	float	t;
	float	dist;

	t = shadow_disk_plane_intersect(dot_light, dot, plane);
	if (t != 0.0f)
	{
		vector_multiply(dot_light, t);
		p = vector_addition(*dot, *dot_light);
		v = vec_sub(p, plane->coord);
		dist = sqrtf(vec_scl(v, v));
		if (p.x == plane->coord.x && p.y == plane->coord.y
			&& p.z == plane->coord.z)
			return (1);
		if (dist <= r)
			return (1);
	}
	return (0);
}

float	shadow_cylindr_intersect(t_coord *dot_light,
	t_cylind *cylind, t_coord *dot)
{
	t_coord	top_disc;
	t_plane	plane;

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
