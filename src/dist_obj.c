/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:44:16 by marlean           #+#    #+#             */
/*   Updated: 2022/07/15 15:55:01 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void nearest_sphere(t_data *data, t_dist *dist, t_coord *ray)
{
	int i;

	i = 0;
	while (i < data->objects.nsphere)
	{
		dist->dist = sphere_intersect(data->scene.camera, *ray, &data->objects.sphere[i]); 
		if (dist->dist > 0 && dist->dist < dist->min_dist)
		{
			dist->min_dist = dist->dist;
			dist->near_obj = 1;
			dist->n_obj = i;
		}
		else
			data->m_dist.near_obj = 0;
		i++;
	}
}
void nearest_plane(t_data *data, t_dist *dist, t_coord *ray)
{
	int i;

	i = 0;
	while (i < data->objects.nplane)
	{
		dist->dist = plane_intersect(data->scene.camera, *ray, &data->objects.plane[i]); 
		if (dist->dist > 0 && dist->dist < dist->min_dist)
		{
			dist->min_dist = dist->dist;
			dist->near_obj = 2;
			dist->n_obj = i;
		}
		i++;
	}
}
void nearest_cylind(t_data *data, t_dist *dist, t_coord *ray)
{
	int i;

	i = 0;
	while (i < data->objects.ncylinder)
	{
		dist->dist = cylindr_intersect(data, *ray, dist, &i); 
		// if (dist->dist > 0 && dist->dist < dist->min_dist)
		// {
		// 	dist->min_dist = dist->dist;
		// 	dist->near_obj = 3;
		// 	dist->n_obj = i;
		// }
		i++;
	}
}