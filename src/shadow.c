/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:16:44 by marlean           #+#    #+#             */
/*   Updated: 2022/07/19 16:08:04 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int shadow_sphere(t_data *data, t_dist *dist, t_coord *ray)
{
	int i;
	float dist_shadow;
	t_coord dot_sphere;

	i = 0;
	while (i < data->objects.nsphere)
	{
		// vector_normalize(dist->dot_light);
		dot_sphere = vector_subtract(data->objects.sphere[i].coord, *ray); // луч из проверяемой точки до центра сферы
		// vector_normalize(&dot_sphere);
		dist_shadow = shadow_sphere_intersect(dist->dot_light, &data->objects.sphere[i], &dot_sphere); //функия возвращает дистанцию от проверяемой точки до каждого объекта на прямой до источника света
		// float len = vector_length(*dist->dot_light);// printf("dist_shadow %f\n", dist_shadow);
		// printf("dot_light len: %f and dist_shadow: %f\n", len, dist_shadow);
		if (dist_shadow > 0.0f && dist_shadow < 1.0f)//vector_length(*dist->dot_light))//проверяемый луч прям до источника света, т.еб если что-то загораживает, то дистанцию надо умножить на число меньше 1
			return (1); //shadow
		i++;
	}
	return (0);
}
int shadow_plane(t_data *data, t_dist *dist, t_coord *ray)
{
	int i;

	i = 0;
	while (i < data->objects.nplane)
	{
		if (shadow_plane_intersect(dist->dot_light, &data->objects.plane[i], ray))
			return (1);
		i++;
	}
	return (0);
}

int shadow_cylinder(t_data *data, t_dist *dist, t_coord *ray)
{
	int i;

	i = 0;
	while (i < data->objects.ncylinder)
	{
		if (shadow_cylindr_intersect(dist->dot_light, &data->objects.cylind[i], ray))
			return (1);
		i++;
	}
	return (0);
}
