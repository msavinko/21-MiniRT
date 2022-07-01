/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:05:45 by marlean           #+#    #+#             */
/*   Updated: 2022/07/01 15:41:01 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	ray_tracing(t_data *data)
{
	(void)data;
// 	int			mlx_x;
// 	int			mlx_y;
// 	double		x_angle;
// 	double		y_angle;
// 	int			color;
// 	double		x_ray;
// 	double		y_ray;
// 	t_coord		ray;
// 	t_vplane	*vplane;

// 	vplane = get_view_plane(WIDTH, HEIGHT, scene->camera->fov);
// 	mlx_y = 0;
// 	y_angle = HEIGHT / 2;
// 	while (y_angle > (-1 * HEIGHT / 2))
// 	{
// 		y_ray = y_angle * vplane->y_pixel;
// 		x_angle = -1 * WIDTH / 2;
// 		mlx_x = 0;
// 		while (x_angle <= WIDTH / 2)
// 		{
// 			x_ray = x_angle * vplane->x_pixel;
// 			ray = new_vector3(x_ray, y_ray, -1);
// 			vector_normalize(ray);
// 			if (sphere_intersect(scene->camera, ray, scene->sphere))
// 				color = 16777215;
// 			else
// 				color = 0;
// 			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
// 			x_angle++;
// 			mlx_x++;
// 		}
// 		y_angle--;
// 		mlx_y++;
// 	}
}

void draw(t_data *data)
{
	
	ray_tracing(data);

}