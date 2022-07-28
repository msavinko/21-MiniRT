/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/28 15:44:45 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	new_vector3(float x, float y, float z)
{
	t_coord	a;

	a.x = x;
	a.y = y;
	a.z = z;
	return (a);
}

t_coord	new_vector(t_coord vec)
{
	t_coord	new;

	new.x = vec.x;
	new.y = vec.y;
	new.z = vec.z;
	return (new);
}

t_coord	vec_sub(t_coord a, t_coord b)
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

float	vec_len(t_coord a)
{
	return (sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}
