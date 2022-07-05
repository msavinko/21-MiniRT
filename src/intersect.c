/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/04 14:39:23 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	sphere_intersect(struct s_camera cam, t_coord *ray, t_sphere *sphere)
{
	double	b;
	double	c;
	double	discr;
	double	dist1;
	double	dist2;
	t_coord	cam_sphere;

	dist1 = 0;
	dist2 = 0;
	if (!sphere)
		return (0);
//	printf("cam.view_point.x = %f\n", cam.view_point.x);
//	printf("sphere.coord.x = %f, sphere.coord.y = %f, sphere.coord.z = %f\n", sphere.coord.x, sphere.coord.y, sphere.coord.z);
	//printf("camera: %f, %f, %f \n", cam.view_point.x, cam.view_point.y, cam.view_point.z);
	//printf("sphere coord %f, %f, %f\n",  sphere->coord.x,  sphere->coord.y,  sphere->coord.z);
	cam_sphere = vector_subtract(cam.view_point, sphere->coord);
	printf("cam_sph.x = %f, cam_sph.y = %f, cam_sph.z = %f\n", cam_sphere.x, cam_sphere.y, cam_sphere.z);
	printf("ray x %f, ray y %f, ray z %f\n", ray->x, ray->y, ray->z);
	b = 2 * (vector_scalar(cam_sphere, *ray));
	//printf("cam_sph.x = %f, cam_sph.y = %f, cam_sph.z = %f\n", cam_sphere.x, cam_sphere.y, cam_sphere.z);

	printf("b = %f\n", b);
	// Неправильно считается скалярное произведение
	c = vector_scalar(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4 * c);
//	free(&cam_sphere);
	if (discr < 0)
		return (0);
	dist1 = ((-1 * b) - sqrt(discr)) / 2;
	dist2 = ((-1 * b) + sqrt(discr)) / 2;
	// printf("dist1: %f\n", dist1);
	// printf("dist2: %f\n", dist2);
	if (dist1 > 0)
		return (1);
	return (0);
}
// Пока оставим без внимания случай, когда камера внутри сферы, иначе надо добавить второй корень, определение,
// лежат ли источник света и какие-то обЪекты внутри этой сферы
