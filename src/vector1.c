/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:39:11 by marlean           #+#    #+#             */
/*   Updated: 2022/07/28 15:45:06 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	vec3_mul(t_coord a, t_coord b)
{
	t_coord	z;

	z.x = a.x * b.x;
	z.y = a.y * b.y;
	z.z = a.z * b.z;
	return (z);
}

t_coord	vec_vec_mul(t_coord a, t_coord b)
{
	t_coord	z;

	z.x = a.y * b.z - a.z * b.y;
	z.y = a.z * b.x - a.x * b.z;
	z.z = a.x * b.y - a.y * b.x;
	return (z);
}

t_coord	mult(t_coord direction, float multiply)
{
	t_coord	new;

	new.x = direction.x * multiply;
	new.y = direction.y * multiply;
	new.z = direction.z * multiply;
	return (new);
}

void	vector_multiply(t_coord *direction, float multiply)
{
	direction->x *= multiply;
	direction->y *= multiply;
	direction->z *= multiply;
}

float	vec_scl(t_coord a, t_coord b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
