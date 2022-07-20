/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/20 13:17:04 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	new_vector3(float x, float y, float z) // Создание нового вектора
{
	t_coord	a;

	// a = malloc(sizeof(t_coord));
	a.x = x;
	a.y = y;
	a.z = z;
	return (a);
}

// t_vector2	new_vector2(float u, float v)
// {
// 	t_vector2	a;

// 	a.u = u;
// 	a.v = v;
// 	return (a);
// }

t_coord	vector_subtract(t_coord a, t_coord b) // Разность векторов
{
	t_coord	difference;
	difference.x = a.x - b.x;
	difference.y = a.y - b.y;
	difference.z = a.z - b.z;
	return (difference);
}

t_coord	vector_add(t_coord a, t_coord b) // Сумма векторов
{
	t_coord	sum;

	// sum = malloc(sizeof(t_coord));
	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	sum.z = a.z + b.z;
	return (sum);
}

float	vector_length(t_coord a) // Длина вектора
{
	return (sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}

void	vector_normalize(t_coord *a) // Нормализация вектора
{
	float	length;

	length = vector_length(*a);
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

t_coord	vector_multiply1(t_coord *direction, float multiply) // Умножение вектора на число
{
	t_coord result;

	result.x = direction->x * multiply;
	result.y = direction->y * multiply;
	result.z = direction->z * multiply;
	return (result);
}

float	vector_sumpow2(t_coord a) // Квадрат длины вектора
{
	return (pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
}

float	vector_scalar(t_coord a, t_coord b) // Скалярное произведение векторов
{
	// printf("a.x %f, a.y %f, a.z %f\n", a.x, a.y, a.z);
	// printf("b.x %f, b.y %f, b.z %f\n", b.x, b.y, b.z);
	// printf("a.x * b.x %f, a.y * b.y % f, a.z * b.z %f\n", a.x * b.x, a.y * b.y, a.z * b.z);
	// printf("return %f\n", a.x * b.x + a.y * b.y + a.z * b.z);
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
