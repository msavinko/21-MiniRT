/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:16:44 by marlean           #+#    #+#             */
/*   Updated: 2022/07/11 13:55:09 by marlean          ###   ########.fr       */
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
		if (dist_shadow > 0 && dist_shadow < 1)//vector_length(*dist->dot_light))//проверяемый луч прям до источника света, т.еб если что-то загораживает, то дистанцию надо умножить на число меньше 1
			return (1);
		i++;
	}
	return (0);
}
int shadow_plane(t_data *data, t_dist *dist, t_coord *ray)
{
	int i;
	float dist_shadow;
	t_coord dot_plane;

	i = 0;
	while (i < data->objects.nplane)
	{
		dot_plane = vector_subtract(data->objects.plane[i].coord, *ray);
		dist_shadow = shadow_plane_intersect(dist->dot_light, &data->objects.plane[i], &dot_plane); //функия возвращает дистанцию от проверяемой точки до каждого объекта на прямой до источника света
		if (dist_shadow > 0 && dist_shadow < 1)///проверяемый луч прям до источника света, т.еб если что-то загораживает, то дистанцию надо умножить на число меньше 1
			return (1);
		i++;
	}
	return (0);
}
// int shadow_cylind(t_data *data, t_dist *dist, t_coord *ray)
// {
// 	int i;
// 	float dist_shadow;
// 	t_coord dot_cylind;

// 	i = 0;
// 	while (i < data->objects.ncylinder)
// 	{
// 		dot_cylind = vector_subtract(data->objects.cylind[i].coord, *ray);
// 		dist_shadow = cylindr_intersect(dist->dot_light, &data->objects.cylind[i], &dot_cylind);
// 		if (dist->dist > 0 && dist->dist < dist->min_dist)
// 		if (dist_shadow > 0 && dist_shadow < 1)//проверяемый луч прям до источника света, т.еб если что-то загораживает, то дистанцию надо умножить на число меньше 1
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }
