/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:27 by marlean           #+#    #+#             */
/*   Updated: 2022/06/30 13:37:29 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere2	*new_sphere2(t_coord *position, double radius, t_color color)
{
	t_sphere2	*sphere;

	sphere = malloc(sizeof(t_sphere2));
	if (!sphere)
		ft_error(1);
	sphere->position = position;
	sphere->radius = radius;
	sphere->color = color;
	return (sphere);
}

int	sphere_intersect2(t_camera2 *cam, t_coord *ray, t_sphere2 *sphere)
{
	double	b;
	double	c;
	double	discr;
	double	dist_1;
	double	dist_2;
	t_coord	*cam_sphere;

	dist_1 = 0;
	dist_2 = 0;
	cam_sphere = vec_subtract(cam->position, sphere->position);
	b = 2 * (vec_scalar(cam_sphere, ray));
	c = vec_scalar(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4 * c);
	free(cam_sphere);
	if (discr < 0)
		return (0);
	dist_1 = ((-1) * b - sqrt(discr)) / 2;
	dist_2 = ((-1) * b + sqrt(discr)) / 2;
	if (dist_1 > 0)
		return (1);
	return (0);
}
