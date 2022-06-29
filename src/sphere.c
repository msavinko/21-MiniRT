/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 19:08:03 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*new_sphere(t_coord position, double radius, t_color color)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		ft_error(1);
	sphere->position = position;
	sphere->radius = radius;
	sphere->color = color;
	return (sphere);
}

int	sphere_intersect(t_camera *cam, t_coord ray, t_sphere *sphere)
{
	double	b;
	double	c;
	double	discr;
	double	dist_1;
	double	dist_2;
	t_coord	cam_sphere;

	dist_1 = 0;
	dist_2 = 0;
	cam_sphere = vector_subtract(cam->position, sphere->position);
	b = 2 * (vector_scalar(cam_sphere, ray));
	c = vector_scalar(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4 * c);
	if (discr < 0)
		return (0);
	dist_1 = ((-1 * b) - sqrt(discr)) / 2;
	dist_1 = ((-1 * b) - sqrt(discr)) / 2;
	if (dist_1 > 0)
		return (1);
	return (0);
}
