/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/28 14:52:11 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	new_vector3(float x, float y, float z) // Создание нового вектора
{
	t_coord	a;

	a.x = x;
	a.y = y;
	a.z = z;
	return (a);
}

t_coord	new_vector(t_coord vec)
{
	t_coord new;

	new.x = vec.x;
	new.y = vec.y;
	new.z = vec.z;
	return (new);
}
t_coord	vec_sub(t_coord a, t_coord b) // Разность векторов
{
	t_coord	difference;
	difference.x = a.x - b.x;
	difference.y = a.y - b.y;
	difference.z = a.z - b.z;
	return (difference);
}

t_coord	vector_addition(t_coord a, t_coord b) // Сумма векторов
{
	t_coord	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	sum.z = a.z + b.z;
	return (sum);
}

float	vec_len(t_coord a) // Длина вектора
{
	return (sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}

void	vector_normalize(t_coord *a) // Нормализация вектора
{
	float	length;

	length = vec_len(*a);
	a->x /= length;
	a->y /= length;
	a->z /= length;
}

void	vector_multiply(t_coord *direction, float multiply) // Умножение вектора на число
{
	direction->x *= multiply;
	direction->y *= multiply;
	direction->z *= multiply;
}

t_coord	mult(t_coord direction, float multiply) // Умножение вектора на число
{
	t_coord	new;

	new.x = direction.x * multiply;
	new.y = direction.y * multiply;
	new.z = direction.z * multiply;
	return (new);
}

float	vector_sumpow2(t_coord a) // Квадрат длины вектора
{
	return (pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
}

float	vec_scl(t_coord a, t_coord b) // Скалярное произведение векторов
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_coord  vec3_mul(t_coord a, t_coord b)
{
	t_coord z;

	z.x = a.x * b.x;
	z.y = a.y * b.y;
	z.z = a.z * b.z;
    return (z);
}

t_coord  vec_vec_mul(t_coord a, t_coord b)
{
	t_coord z;

    z.x = a.y * b.z - a.z * b.y;
    z.y = a.z * b.x - a.x * b.z;
    z.z = a.x * b.y - a.y * b.x;
    return (z);
}

