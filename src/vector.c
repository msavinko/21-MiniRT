/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/04 13:20:07 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	new_vector3(double x, double y, double z) // Создание нового вектора
{
	t_coord	a;

	// a = malloc(sizeof(t_coord));
	a.x = x;
	a.y = y;
	a.z = z;
	return (a);
}

// t_vector2	new_vector2(double u, double v)
// {
// 	t_vector2	a;

// 	a.u = u;
// 	a.v = v;
// 	return (a);
// }

t_coord	vector_subtract(t_coord a, t_coord b) // Разность векторов
{
	t_coord	difference;

	// printf("a.x = %f\n", a.x);
	// printf("a.y = %f\n", a.y);
	// printf("a.z = %f\n", a.z);
	// printf("b.x = %f\n", b.x);
	// printf("b.y = %f\n", b.y);
	// printf("b.z = %f\n", b.z);
	// difference = malloc(sizeof(t_coord));
	// if (!difference)
	// 	exit (1);
	difference.x = a.x - b.x;
	difference.y = a.y - b.y;
	difference.z = a.z - b.z;
	return (difference);
}

// t_coord	vector_addition(t_coord a, t_coord b) // Сумма векторов
// {
// 	t_coord	sum;

// 	// sum = malloc(sizeof(t_coord));
// 	sum.x = a.x + b.x;
// 	sum.y = a.y + b.y;
// 	sum.z = a.z + b.z;
// 	return (sum);
// }

double	vector_length(t_coord a) // Длина вектора
{
	return (sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}

void	vector_normalize(t_coord *a) // Нормализация вектора
{
	double	length;

	length = vector_length(*a);
	a->x /= length;
	a->y /= length;
	a->z /= length;
}

// void	vector_multiply(t_coord *direction, double multiply) // Умножение вектора на число
// {
// 	direction->x *= multiply;
// 	direction->y *= multiply;
// 	direction->z *= multiply;
// }

double	vector_sumpow2(t_coord a) // Квадрат длины вектора
{
	return (pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
}

double	vector_scalar(t_coord a, t_coord b) // Скалярное произведение векторов
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
