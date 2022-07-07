/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/07/07 14:07:37 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int sphere_intersect(struct s_camera cam, t_coord ray, t_sphere *sphere)
{
	float	b;
	float	c;
	float	discr;
	float	dist;
	t_coord	cam_sphere;
	t_coord	a;
	float a2;

	if (!sphere)
		return (0);
 	cam_sphere = vector_subtract(cam.view_point, sphere->coord);
	//printf("sphere->coord %f, %f, %f\n", sphere->coord.x, sphere->coord.y, sphere->coord.z);
	//printf("cam_sphere %f, %f, %f\n", cam_sphere.x, cam_sphere.y, cam_sphere.z);
	a = vector_subtract(ray, cam.view_point);
	//printf("a: %f %f %f\n", a.x, a.y, a.z);
	a2 = vector_scalar(a, a);
	//printf("a2: %f \n", a2);
	b = 2.0f * (vector_scalar(cam_sphere, ray));
	// printf("ray %f, %f, %f\n", ray.x, ray.y, ray.z);
	// printf("vector_scalar cam_sphere, ray %f\n", vector_scalar(cam_sphere, ray));
	//printf("b = %f\n", b);
	// Неправильно считается скалярное произведение
	
	c = vector_scalar(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	//printf("vector scalar %f\n", vector_scalar(cam_sphere, cam_sphere) );
	//printf("sphere-radius %f\n", sphere->radius);
	//printf("r2 %f\n",sphere->radius * sphere->radius);
	//printf("c: %f\n", c);
	discr = (b * b) - (4.0f * c);
	//printf("discr: %f\n", discr);
//	free(&cam_sphere);
	// if (discr < 0)
	// 	return (0);
 	//dist = ((-1.0f * b) - sqrt(discr)) / 2.0f;
	// k1 = vector_scalar(cam.orient_vector, cam.orient_vector); 
	// k2 = 2 * vector_scalar (cam_sphere, ray);
	// k3 = vector_scalar(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	//discr = (k2 * k2) - (4 *k1 *k3);
	if (discr < 0)
		return (0);
	dist = (-1 * b - sqrt(discr)) / 2;
	//printf("dist %f\n", dist);
	//printf("k1 %f, k2 %f, k3 %f, discr %f, dist %f\n", k1, k2, k3, discr, dist);
	if (dist > 0.0f)
		return (dist);
	return (0);
}
// Пока оставим без внимания случай, когда камера внутри сферы, иначе надо добавить второй корень, определение,
// лежат ли источник света и какие-то обЪекты внутри этой сферы


int	plane_intersect(struct s_camera cam, t_coord ray,  t_plane *plane)
{
	float	d;
	float c;
	float pn;
	float dist;

	c = vector_scalar(plane->orient_vector, ray);
	if (c == 0)
		return (0);
	d =  plane->coord.z; 
	pn = vector_scalar(cam.view_point, plane->orient_vector);
	dist = (d - pn) /c;
	if (dist < 0)
		return (0);
	return (dist);

}

int	cylindr_intersect(struct s_camera cam, t_coord ray,  t_cylind *cylind)
{
	float	dist;
	float	a;
	float	b;
	float	c;
	float m;
	float	discr;
	t_coord	cam_cy;

	//printf("cylind center %f, %f, %f\n", cylind->coord.x,  cylind->coord.y,  cylind->coord.z);
	cam_cy = vector_subtract(cylind->coord, cam.view_point);
	//printf("cylind orient %f, %f, %f\n", cylind->orient_vector.x,  cylind->orient_vector.y,  cylind->orient_vector.z);
	vector_normalize(&cylind->orient_vector);
	//printf("normalized cylind orient %f, %f, %f\n", cylind->orient_vector.x,  cylind->orient_vector.y,  cylind->orient_vector.z);
	a = 1 - pow(vector_scalar(ray, cylind->orient_vector), 2);
	b = -2 * (vector_scalar(ray, cam_cy) - vector_scalar(ray, cylind->orient_vector) * vector_scalar(cam_cy,cylind->orient_vector));
	c = vector_scalar(cam_cy, cam_cy) - pow(vector_scalar(cam_cy, cylind->orient_vector), 2) - (cylind->diameter / 2) * (cylind->diameter / 2);
	//printf("diametr %f\n", cylind->diameter);
	//printf("height %f\n", cylind->height);
	discr = (b * b) - (4.0f *a * c);
	if (discr < 0)
		return (0);
	dist = (-b - sqrtf(discr)) / (2 * a);
	m = vector_scalar(ray, cylind->orient_vector) * dist - vector_scalar(cam_cy, cylind->orient_vector);
	//printf("m %f\n", m);
	if (dist > 0 && m >= 0 && m <= cylind->height)
		return (dist);
	return (0);
}