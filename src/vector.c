/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 19:08:03 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	new_vector3(double x, double y, double z)
{
	t_coord	a;

	a.x = x;
	a.y = y;
	a.z = z;
	return (a);
}

t_vector2	new_vector2(double u, double v)
{
	t_vector2	a;

	a.u = u;
	a.v = v;
	return (a);
}

t_coord	vector_subtract(t_coord a, t_coord b)
{
	t_coord	difference;

	difference.x = a.x - b.x;
	difference.y = a.y - b.y;
	difference.z = a.z - b.z;
	return (difference);
}

t_coord	vector_addition(t_coord a, t_coord b)
{
	t_coord	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	sum.z = a.z + b.z;
	return (sum);
}

double	vector_length(t_coord a)
{
	double	result;

	result = sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	return (result);
}

void	vector_normalize(t_coord a)
{
	double	length;

	length = vector_length(a);
	a.x /= length;
	a.y /= length;
	a.z /= length;
}

t_coord	vector_multiply(t_coord direction, double multiply)
{
	direction.x *= multiply;
	direction.y *= multiply;
	direction.z *= multiply;
	return (direction);
}

double	vector_sumpow2(t_coord a)
{
	return (pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
}

double	vector_scalar(t_coord a, t_coord b) // vec_dot_product
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
