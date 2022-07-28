/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:20:46 by marlean           #+#    #+#             */
/*   Updated: 2022/07/28 14:52:39 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	dot_normal_cylind(t_data *data, t_dist *dist,
	t_coord *dot, t_coord *normal)
{
	float	n;
	t_coord	tmp;

	tmp = vec_sub(data->objects.cylind[dist->n_obj].coord, *dot);
	vector_normalize(&data->objects.cylind[dist->n_obj].orient_vector);
	n = -vec_scl(tmp,
			data->objects.cylind[dist->n_obj].orient_vector);
	normal->x = -(data->objects.cylind[dist->n_obj].orient_vector.x * n
			+ data->objects.cylind[dist->n_obj].coord.x - dot->x);
	normal->y = -(data->objects.cylind[dist->n_obj].orient_vector.y * n
			+ data->objects.cylind[dist->n_obj].coord.y - dot->y);
	normal->z = -(data->objects.cylind[dist->n_obj].orient_vector.z * n
			+ data->objects.cylind[dist->n_obj].coord.z - dot->z);
	vector_normalize(normal);
	vector_normalize(dist->dot_light);
}

float	dot_normal(t_data *data, t_dist *dist, t_coord *dot)
{
	t_coord	*normal;
	float	intens_light;

	normal = malloc(sizeof(t_coord));
	if (dist->near_obj == SPHERE)
		*normal = vec_sub(*dot,
				data->objects.sphere[dist->n_obj].coord);
	else if (dist->near_obj == PLANE)
		*normal = new_vector(data->objects.plane[dist->n_obj].orient_vector);
	else if (dist->near_obj == CYLINDER)
		dot_normal_cylind(data, dist, dot, normal);
	else if (dist->near_obj == TOP_DISK)
		*normal = new_vector(data->objects.cylind[dist->n_obj].orient_vector);
	else
		*normal = mult(data->objects.cylind[dist->n_obj].orient_vector, -1.0f);
	vector_normalize(normal);
	intens_light = vec_scl(*dist->dot_light, *normal)
		/ vec_len(*dist->dot_light) / vec_len(*normal);
	if (intens_light < 0)
		intens_light = 0;
	return (intens_light);
}
