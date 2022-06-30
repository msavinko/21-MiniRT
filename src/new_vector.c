/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:39:40 by rdanyell          #+#    #+#             */
/*   Updated: 2022/06/30 13:37:57 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	*new_vec(double x, double y, double z)
{
	t_coord	*vec;

	vec = malloc(sizeof(t_coord));
	if (!vec)
		ft_exit(-1);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

double	vec_length(t_coord *a)
{
	double	result;

	result = sqrt((a->x * a->x) + (a->y * a->y) + (a->z * a->z));
	return (result);
}

t_coord	*vec_subtract(t_coord *a, t_coord *b)
{
	t_coord	*difference;

	difference = malloc(sizeof(t_coord));
	difference->x = a->x - b->x;
	difference->y = a->y - b->y;
	difference->z = a->z - b->z;
	return (difference);
}

void	vec_normalize(t_coord *a)
{
	double	length;

	length = vec_length(a);
	a->x /= length;
	a->y /= length;
	a->z /= length;
}


t_coord	*vec_addition(t_coord *a, t_coord *b)
{
	t_coord	*sum;

	sum = malloc(sizeof(t_coord));
	sum->x = a->x + b->x;
	sum->y = a->y + b->y;
	sum->z = a->z + b->z;
	return (sum);
}

double	vec_scalar(t_coord *a, t_coord *b) // vec_dot_product
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}

// t_coord	vec_multiply(t_coord direction, double multiply)
// {
// 	direction.x *= multiply;
// 	direction.y *= multiply;
// 	direction.z *= multiply;
// 	return (direction);
// }

// double	vector_sumpow2(t_coord a)
// {
// 	return (pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
// }
