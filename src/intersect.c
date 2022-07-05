/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariasavinova <mariasavinova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/05 21:35:14 by mariasavino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int sphere_intersect(struct s_camera cam, t_coord ray, t_sphere *sphere)
{
	float b;
	float c;
	float discr;
	float dist;
	t_coord cam_sphere;

	dist = 0;
	if (!sphere)
		return (0);
	cam_sphere = vector_subtract(cam.view_point, sphere->coord);
	b = 2.0f * (vector_scalar(cam_sphere, ray));
	// printf("b = %.2f\n", b);
	// Неправильно считается скалярное произведение
	c = vector_scalar(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	// printf("radius: %.2f\n", sphere->radius);
	discr = (b * b) - (4.0f * c);
	//	free(&cam_sphere);
	if (discr < 0)
		return (0);
	dist = ((-1.0f * b) - sqrt(discr)) / 2.0f;
	if (dist > 0.0f)
		return (dist);
	return (0);
}
// Пока оставим без внимания случай, когда камера внутри сферы, иначе надо добавить второй корень, определение,
// лежат ли источник света и какие-то обЪекты внутри этой сферы
