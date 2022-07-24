/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherrie <mcherrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:57:35 by rdanyell          #+#    #+#             */
/*   Updated: 2022/07/15 13:23:57 by mcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_discr(t_camera cam, t_coord ray, t_cylind *cylind, t_coef *coef)
{
	t_coord	cam_cy;

	cam_cy = vector_subtract(cylind->coord, cam.view_point);
	vector_normalize(&cylind->orient_vector);
	coef->a = 1 - pow(vector_scalar(ray, cylind->orient_vector), 2);
	coef->b = -2 * (vector_scalar(ray, cam_cy) - vector_scalar(ray, \
		cylind->orient_vector) * vector_scalar(cam_cy, cylind->orient_vector));
	coef->c = vector_scalar(cam_cy, cam_cy) - pow(vector_scalar(cam_cy, \
		cylind->orient_vector), 2) - (cylind->diameter / 2) * \
		(cylind->diameter / 2);
	coef->discr = (coef->b * coef->b) - (4.0f * coef->a * coef->c);
}

void	get_nearest(t_dist *dist, float dist_min, float *dist_disc, int *i)
{
	if (dist_min < dist->min_dist)
	{
		dist->min_dist = dist_min;
		dist->near_obj = 3;
		if (dist_min == dist_disc[0])
			dist->near_obj = 4;
		if (dist_min == dist_disc[1])
			dist->near_obj = 5;
		dist->n_obj = *i;
	}
}

void	get_plane(t_plane *plane, t_cylind cylind)
{
	plane->coord = cylind.coord;
	plane->orient_vector = cylind.orient_vector;
	plane->color = cylind.color;
}
