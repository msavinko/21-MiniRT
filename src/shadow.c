/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:16:44 by marlean           #+#    #+#             */
/*   Updated: 2022/07/08 14:35:27 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int shadow_sphere(t_data *data, t_dist *dist, t_coord * ray)
{
	int i;
	float dist_shadow;
	t_coord dot_sphere;

	i = 0;
	while (i < data->objects.nsphere)
	{
		dot_sphere = vector_subtract(data->objects.sphere[i].coord, *ray);// луч из проверяемой точки до центра сферы
		dist_shadow = shadow_sphere_intersect(dist->dot_light, &data->objects.sphere[i], &dot_sphere); //функия возвращает дистанцию от проверяемой точки до каждого объекта на прямой до источника света
		if (dist_shadow > 0 && dist_shadow < 1)//vector_length(*dist->dot_light))
			return (1);
		i++;
	}
	return (0);
}
// void shadow_plane(t_data *data, t_dist *dist, t_coord *ray)
// {
// 	int i;

// 	i = 0;
// 	while (i < data->objects.nplane)
// 	{
// 		dist->dist = plane_intersect(data->scene.camera, *ray, &data->objects.plane[i]); 
// 		if (dist->dist > 0 && dist->dist < dist->min_dist)
// 		{
// 			dist->min_dist = dist->dist;
// 			dist->near_obj = 2;
// 			dist->n_obj = i;
// 		}
// 		i++;
// 	}
// }
// void shadow_cylind(t_data *data, t_dist *dist, t_coord *ray)
// {
// 	int i;

// 	i = 0;
// 	while (i < data->objects.ncylinder)
// 	{
// 		dist->dist = cylindr_intersect(data->scene.camera, *ray, &data->objects.cylind[i]); 
// 		if (dist->dist > 0 && dist->dist < dist->min_dist)
// 		{
// 			dist->min_dist = dist->dist;
// 			dist->near_obj = 3;
// 			dist->n_obj = i;
// 		}
// 		i++;
// 	}
// }
