/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:16:44 by marlean           #+#    #+#             */
/*   Updated: 2022/07/28 15:09:22 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	shadow_sphere(t_data *data, t_dist *dist, t_coord *ray)
{
	int		i;
	t_coord	dot_sph;
	t_coord	lgt_sph;

	i = 0;
	while (i < data->objects.nsphere)
	{
		if (dist->near_obj != SPHERE || (i != dist->n_obj
				&& dist->near_obj == SPHERE))
		{
			dot_sph = vec_sub(data->objects.sphere[i].coord,*ray);
			lgt_sph = vec_sub(data->objects.sphere[i].coord,*dist->dot_light);
			if ((vec_len(dot_sph) < data->objects.sphere[i].radius && vec_len(lgt_sph) > data->objects.sphere[i].radius) || (vec_len(dot_sph) > data->objects.sphere[i].radius && vec_len(lgt_sph) < data->objects.sphere[i].radius))
				return (1);
			if (((vec_len(dot_sph) > data->objects.sphere[i].radius && vec_len(lgt_sph) > data->objects.sphere[i].radius)) && (vec_scl(dot_sph, *dist->dot_light) > 0 && vec_scl(lgt_sph, *dist->dot_light) < 0))
				if ((vec_len(vec_vec_mul(dot_sph, *dist->dot_light)) / vec_len(*dist->dot_light) < data->objects.sphere[i].radius) || vec_len(vec_vec_mul(dot_sph, lgt_sph)) / vec_len(*dist->dot_light) == 0)
					return (1);
		}
		i++;
	}
	return (0);
}

int	shadow_plane(t_data *data, t_dist *dist, t_coord *ray)
{
	int		i;
	t_coord	pld;
	t_coord	pll;

	i = 0;
	while (i < data->objects.nplane)
	{
		if (dist->near_obj != PLANE
			|| (i != dist->n_obj && dist->near_obj == PLANE))
		{
			pld = vec_sub(*ray, data->objects.plane[i].coord);
			pll = vec_sub(data->scene.light.coord,
					data->objects.plane[i].coord);
			if ((vec_scl(pld, data->objects.plane[i].orient_vector) > 0
					&& vec_scl(pll, data->objects.plane[i].orient_vector) < 0)
				|| (vec_scl(pld, data->objects.plane[i].orient_vector) < 0
					&& vec_scl(pll, data->objects.plane[i].orient_vector) > 0))
				return (1);
		}
		i++;
	}
	return (0);
}

int	shadow_cylinder(t_data *data, t_dist *dist, t_coord *ray)
{
	int	i;

	i = 0;
	while (i < data->objects.ncylinder)
	{
		if (shadow_cylindr_intersect(dist->dot_light,
				&data->objects.cylind[i], ray))
			return (1);
		i++;
	}
	return (0);
}
