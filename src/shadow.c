/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:16:44 by marlean           #+#    #+#             */
/*   Updated: 2022/07/21 14:26:55 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int shadow_sphere(t_data *data, t_dist *dist, t_coord *ray)
{
	int i;
	float dist_shadow;
	t_coord *dot_sphere;

	i = 0;
	while (i < data->objects.nsphere)
	{
		if (dist->near_obj != SPHERE || (i != dist->n_obj && dist->near_obj == SPHERE))
		{
			dot_sphere = malloc(sizeof(t_coord));
		//	printf("\nBEFORE NORM dot_light.x %f dot_light.y %f dot_light.z %f\n", dist->dot_light->x, dist->dot_light->y, dist->dot_light->z);
		//	vector_normalize(dist->dot_light);
		//	printf("AFTER NORM dot_light.x %f dot_light.y %f dot_light.z %f\n", dist->dot_light->x, dist->dot_light->y, dist->dot_light->z);
			*dot_sphere = vector_subtract(data->objects.sphere[i].coord, *ray);// луч из проверяемой точки до центра сферы
		//	printf("\nBEFORE NORM dot_sphere.x %f dot_sphere.y %f dot_sphere.z %f\n", dot_sphere->x, dot_sphere->y, dot_sphere->z);
		//	vector_normalize(dot_sphere);
		//	printf("AFTER NORM dot_sphere.x %f dot_sphere.y %f dot_sphere.z %f\n", dot_sphere->x, dot_sphere->y, dot_sphere->z);

			dist_shadow = shadow_sphere_intersect(dist->dot_light, &data->objects.sphere[i], dot_sphere); //функия возвращает дистанцию от проверяемой точки до каждого объекта на прямой до источника света
			printf("ray.x %f ray.y %f ray.z %f ", ray->x, ray->y, ray->z);
			printf("dist_shadow %f \n", dist_shadow);
			free(dot_sphere);
			if (dist_shadow > 0.0f && dist_shadow < vector_length(*dist->dot_light))//проверяемый луч прям до источника света, т.еб если что-то загораживает, то дистанцию надо умножить на число меньше 1
				return (1);
		}
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
